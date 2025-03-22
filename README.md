# libprjx
Forsaken ProjectX C++ library 

## Goals ##
- support platform independent frameworks
- support forsaken file formats
- support checksum algorithm
- support aligned linalg simd types

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
## Usage ##

```cpp

using namespace prjx::math;
using namespace prjx::checksum;
using namespace prjx::file;

```

## Links ##
- [Forsaken: Remastered](https://www.mobygames.com/game/111883/forsaken-remastered/)
- [ForsakenX](https://github.com/ForsakenX)
- [ForsakenW](https://github.com/ForsakenW)
- [Forsaken ProjectX Windows Direct3D Source](https://github.com/commercial-game-sources/forsaken)
- [Forsaken 64 Level/Model Viewer](https://github.com/hack64-net/rotm/tree/master/forsaken_64)
- [Forsaken OST FLAC](https://downloads.khinsider.com/game-soundtracks/album/forsaken-the-music)
- [Forsaken 64 OST USF](https://www.zophar.net/music/nintendo-64-usf/forsaken-64)
