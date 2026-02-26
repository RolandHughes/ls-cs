# LsCs Cross Platform Library for Desktops and Embedded Systems Development

*This is project is not maintained by the CopperSpice project and we no longer accept code from them.*

All library files have been renamed in case CopperSpice project gets around to making formal official package releases in the next 15-20 years. Another reason for this fork is to stop the maniacal pursuit of newer C++ standards that have no connection to production realities.

In particular ***C++20 will never be required/used for this fork***. When C++20 and now C++23 forced integer values to be Two's Complement it completely ignored the fact that Unisys MainFrames are One's Complement and the machines that process the largest amount of financial transactions globally. The Internal Revenue Service in America uses them to process all tax returns in a timely manner. Nothing else comes close to the raw throughput. One's Complement is the most efficient for scaled integer add/subtract functions. There is also packed decimal to consider.

Many multi-national banks are using these same machines for the very same reason. When "front end" systems written in C++ running on "commodity" hardware try to pass back "integer" values it reeks havoc. Just ask all of the college students whose financial aid applications got jacked up by it for the 2024 school year because front ends ass-u-me-d integer was integer.

Initially we will focus on formal packaging: Deb, RPM, as well as ArmV8 for embedded systems. Toradex will be target of choice because it is what we have. All NXP derived ArmV8 should be able to utilize the code.

**currently requires C++17 or newer.**

## Transitional
Versions 0.2.1 and later are transitional experiments for things that may become part of [BasisDoctrina](https://sourceforge.net/projects/basisdoctrina/).

Completed:
* dropped support for Ubuntu 18.04 it may still work but you need newer versions of CMake and a few other things.
* removed webkit
* removed qdeclarative
* removed system strings that said CopperSpice
* added Liberation Sans font
* removed mingw support
* local build now deploys cmake files along with lscs.conf
* removed RPATH ${origin}hacking CopperSpice relied upon. Secured environments will not allow you to do that.
* cleaned up the install directory tree.
* lscs.conf is now found where it should be and most legacy bugs that still exists in Qt today of not respecting paths is fixed. Cannot fix Libraries conf issue because Gnu LibTool does not work as advertised. It is supposed to have a compile option that will let it use itself to open all dependencies down the tree, but the official developer mailing list can't figure out how to make that work. Documentation for the project is really poor.

Remaining:
* Modernize CUPS support.
* VCPKG build on Windows


### Contributing
No contributions.
Once version 0.3.5 is fully packaged for Debian and RPM, this project will officially be abandoned. 

[LsX](https://codeberg.org/seasoned_geek) will be the re-branded package hosted on codeberg.org LsX will also get rid of most/all plugins. SDL3 will be its platform getting rid of a ton of legacy bugs and code. 

The purpose of LsX is to experiment with using SDL3 as a base for a robust library so we can put what we learn into [BasisDoctrina](https://sourceforge.net/projects/basisdoctrina/).


## System Requirements

To use the LsCs libraries a C++17 compiler and a C++17 standard library are required. In the root directory you will find the following to install build dependencies:

1. LsCs-Deb-build-dependencies.sh       - for Debian based distros like Ubuntu
2. LsCs-Manjaro-build-dependencies.sh - for Manjaro based distros
3. LsCs-RPM-build-dependencies.sh      - for RPM based distros like OpenSuSE

The above install some extra development tools. If you are installing on a distro that is much older (or newer) than currently being used for development you might have to tweak a few version numbers. They install everything you need to build a package for distribution.

LsCs CMake build files are provided with the source distribution. 

You will also find:

1. build-LsCs-deb.sh   -   Build a DEB package
2. build-LsCs-rpm.sh   -   Build an RPM package
3. local-build.sh      -   Build and install into a local directory tree


### Building

Once you have successfully run a dependency script you can use one of the build scripts to build a package or a local development install.


### Documentation

For now there is only the CopperSpice documentation and it is quite a bit different from where we are.

https://www.copperspice.com/documentation-copperspice.html

You could also run Doxygen against the source to generate local documentation.

You can download from that site for off-line use. At some point we will gen our own documentation. Once significant changes happen, like changing of string classes, that will be a necessity.

### License

This library is released under the LGPL V2.1 license. For more information refer to the LICENSE directory provided with this project.

Would like to re-license under Eclipse Public License but a lot more CopperSpice/Qt code has to disappear first.

### References

 Code:  https://github.com/RolandHughes/ls-cs
 Website: https://lscs-software.com/

Users who do not know me may register at the forum for my blog to post comments.

 https://www.logikalsolutions.com/wordpress/forum/

I guess you could try messaging me on GitHub too, but I don't hang out there.

