# Ls-Cs Cross Platform Library for Desktops and Embedded Systems Development

*This is project is not maintained by the CopperSpice project and we no longer
accept code from them.*

All library files have been renamed in case CopperSpice project gets
around to making formal official package releases in the next 15-20 years.
Another reason for this fork is to stop the maniacal pursuit of newer C++
standards that have no connection to production realities.

In particular ***C++20 will never be required/used for this fork***. When
C++20 and now C++23 forced integer values to be Two's Complement it
completely ignored the fact that Unisys MainFrames are One's Complement
and the machines that process the largest amount of financial transactions
globally. The Internal Revenue Service in America uses them to process
all tax returns in a timely manner. Nothing else comes close to the raw
throughput. One's Complement is the most efficient for scaled integer
add/subtract functions. There is also packed decimal to consider.

Many multi-national banks are using these same machines for the very
same reason. When "front end" systems written in C++ running on "commodity"
hardware try to pass back "integer" values it reeks havoc. Just ask all of
the college students whose financial aid applications got jacked up by it
for the 2024 school year because front ends ass-u-me-d integer was integer.

Initially we will focus on formal packaging: Deb, RPM, Manjaro as well as
ArmV8 for embedded systems. Toradex will be target of choice because it is
what we have. All NXP derived ArmV8 should be able to utilize the code.

You can read the CopperSpice README.md here:
https://github.com/copperspice/copperspice

The original licese was LGPL V2.1 for CopperSpice. Right now not worth the
pain of trying to flip it to BSD. Oddly enough it included these libraries
that were BSD.

 * CsCrypto
 * CsLibGuarded
 * CsPaint
 * CsPointer
 * CsSignal
 * CsString

Don't worry if you already have them installed. Any included with this
get Ls added in front of the Cs so we don't have any naming/linking
collisions. 

**currently requires C++17 or newer.**

## Introduction
CopperSpice was a fork of one of the last true OpenSource versions of 
Qt 4.8.x with most of the QML removed along with other improvements. It 
also has some academic debacles. One of the main ones is the removal of
Copy-On-Write. Yes, academics declared CoW bad and incompatible with 
exceptions but the speed improvement of CoW was and still is dramatic.
See:
https://www.logikalsolutions.com/wordpress/information-technology/qlist/

It is theoretically possible to implement CoW making the existing 
QString typedef a wrapper class around the current QString8 and 
QStringView making all pre-existing initial assignments a view until a write
happens, but no work has been done on that in this library yet.
https://www.copperspice.com/docs/cs_api/class_qstring8.html
https://www.copperspice.com/docs/cs_api/class_qstringview.html

### Contributing
This is a young project with an old base. As such there is much along the lines of "grunt work" which would be great for beginning coders who need to how to use tools and get their feet wet with real projects. Must follow the [coding standard](https://lscs-software.com/LsCs-CodingStandard.html). In fact one of the early grunt work projects is converting the code base to the new coding standard prefered by embedded systems projects. In fact, fixing QComboBox should be a quick hit for one with just a bit of coding experience.

Purging the legacy display plugins making GLFW the singular graphics layer this library communicates with will require someone with a bit more skill.

Keep in mind this project cares primarily about embedded systems and secondarily about desktops. It will _never_ care about phones.

## System Requirements

To use the LsCs libraries a C++17 compiler and a C++17 standard library are 
required. In the root directory you will find the following to install build
dependencies:

1. LsCs-Deb-build-dependencies.sh       - for Debian based distros like Ubuntu
2. LsCs-Manjaro-build-dependencies.sh - for Manjaro based distros
3. LsCs-RPM-build-dependencies.sh      - for RPM based distros like OpenSuSE

The above install some extra development tools. If you are installing on a 
distro that is much older (or newer) than currently being used for development
you might have to tweak a few version numbers. They install everything you need
to build a package for distribution.

LsCs CMake build files are provided with the source distribution. 
You will also find:

1. build-LsCs-deb.sh   -   Build a DEB package
2. build-LsCs-rpm.sh   -   Build an RPM package
3. local-build.sh           -   Build and install into a local directory tree


### Building

Once you have successfully run a dependency script you can use one of the build
scripts to build a package or a local development install.


### Using the Ls-Cs Libraries

In a few weeks RedDiamond should be ported to use Ls-Cs instead of CopperSpice.
https://sourceforge.net/p/reddiamond/code/ci/master/tree/

You will note that project also has build*.sh files Thieving just a few files
from that project should jumpstart your use of LsCs.

As time allows examples will be added to this code base and instructions for them added to [the primary Web site](https://lscs-software.com/).

### Documentation

For now there is only the CopperSpice documentation.

https://www.copperspice.com/documentation-copperspice.html

You could also run Doxygen against the source to generate local documentation.

You can download from that site for off-line use. At some point we will gen
our own documentation. Once significant changes happen, like changing of
string classes, that will be a necessity.

### License

This library is released under the LGPL V2.1 license. For more information refer to the LICENSE file provided with
this project.


### References

 Code:  https://github.com/RolandHughes/ls-cs
 Website: https://lscs-software.com/

 Users who do not know me may register at the forum for my blog to post
 comments.

 https://www.logikalsolutions.com/wordpress/forum/

 I guess you could try messaging me on GitHub too, but I don't hang out
 there.

