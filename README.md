# prjxsum
Forsaken ProjectX [checksum](https://github.com/jopadan/prjxsum/wiki/Checksum) calculation tool.

## Forsaken ProjectX Checksum ##

Iterating in `3 byte steps` and `shifting` them cast to `u64` by a `(0..31) clamped multiple of 7`.
Writing out all the shift amount and the results I came up with the sequence
`(2,3,5|7|14,21,28|31|35|37)` alternating between `prime numbers` and `multiples of 7` and the term `LFSL`
Use the sequence to generate `Mersenne primes` as the `loop shift step`.

```cpp
    constexpr i64 compute_block( u8 buf[4096], u64 len, u32 shl = 0)
    {
        i64 ret = 0;

        for(; len>=((1<<2)-1); buf+=(1<<2)-1, len-=(1<<2)-1, shl=(shl + ((1<<3)-1)) % (1<<5))
            ret += ((i64)le32toh(*(u32*)buf & 0x00FFFFFF)) << shl;
        if(len > 0)
            ret += ((i64)le16toh(*(u16*)buf & (len == 2 ? 0xFFFF : 0x00FF))) << shl;
        return ret;  
    }
```
## Example ##
```sh
prjxsum -r data/levels

0033edcdbe539ba0 *data/levels/accworld/accworld.bsp
63f04c40700994f6 *data/levels/alpha/alpha.bsp
5abe6fdc6c8805a7 *data/levels/arena/arena.bsp
6666a6ef564aa3a5 *data/levels/asteroid/asteroid.bsp
4055f871a6c94a95 *data/levels/astro/astro.bsp
5b41245d017b4439 *data/levels/asubchb/asubchb.bsp
7fbb19a1d8dabd3d *data/levels/azchb/azchb.bsp
b0dccc483a3accd6 *data/levels/azt-sp01/azt-sp01.bsp
7fbb19a1d8dabd3d *data/levels/aztec/aztec.bsp
```
## Links ##
- [Forsaken: Remastered](https://www.mobygames.com/game/111883/forsaken-remastered/)
- [ForsakenX](https://github.com/ForsakenX)
- [ForsakenW](https://github.com/ForsakenW)
- [Forsaken ProjectX Windows Direct3D Source](https://github.com/commercial-game-sources/forsaken)
- [Forsaken 64 Level/Model Viewer](https://github.com/hack64-net/rotm/tree/master/forsaken_64)
- [Forsaken OST FLAC](https://downloads.khinsider.com/game-soundtracks/album/forsaken-the-music)
- [Forsaken 64 OST USF](https://www.zophar.net/music/nintendo-64-usf/forsaken-64)
