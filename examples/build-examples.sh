#!/bin/bash
#
# Build LsCs examples
#
#
echo " "
echo "USAGE: ./build_examples.sh"
echo " "

#  Step 1 : Establish variable values
#
echo " "
echo "*** Establishing directory variables"
echo " "
SCRIPT_DIR="$PWD"
EXAMPLES_DIR="$SCRIPT_DIR"
BUILD_BASE_DIR="$SCRIPT_DIR/../../LsCs_examples_build"
INSTALL_BASE_DIR="$SCRIPT_DIR/../../LsCs_examples_install"

prefix_dir="$LsCs_DIR"
local_build=true



# I know, I probably should have some range safety here, but that
# is a bit of overkill at this point. If the directory doesn't exist
# we will catch that.
#
build_one(){
    EXMPL=$1
    if [ ! -z "$EXMPL" ]; then
        NM="$EXMPL"
        S_DIR="$EXAMPLES_DIR/$NM"
        B_DIR="$BUILD_BASE_DIR/$NM"
        I_DIR="$INSTALL_BASE_DIR/$NM"
        if [ -d "$S_DIR" ]; then
            echo " "
            echo "Building $NM from $S_DIR into $B_DIR and installing to $I_DIR"
            echo " "
            if [ -d "$B_DIR" ]; then
                rm -rf "$B_DIR"
            fi
            if [ -d "$I_DIR" ]; then
            	rm -rf "$I_DIR"
            fi
            #
            # skipping deletion of install dir in case someone tweaks that to be
            # something like /usr/bin. Nuking that would be bad. If they are
            # building in /usr/bin they deserve what they get.
            #
            mkdir -p "$B_DIR"
            mkdir -p "$I_DIR"

            # change to directory just in case
            #
            cd "$B_DIR"

            # You can change build type from Release to Debug if you want
            # Older versions of CMAKE_PREFIX_PATH allowed/required a space between ; and next list item
            # latest version will gag if there is a space.
            #
            if [ "$local_build" = true ] ; then
                
                cmake -G "Ninja" \
                      -DCMAKE_BUILD_TYPE=Debug \
                      -DCMAKE_INSTALL_PREFIX="$I_DIR" \
                      -DCMAKE_PREFIX_PATH="$prefix_dir" \
                      -S "$S_DIR" \
                      -B "$B_DIR"
            else
                cmake -G "Ninja" \
                      -DCMAKE_BUILD_TYPE=Debug \
                      -DCMAKE_INSTALL_PREFIX="$I_DIR" \
                      -S "$S_DIR" \
                      -B "$B_DIR"
            fi
            
            ninja install
        fi
    fi


}

build_all(){
    # yes I could use a loop of some kind here, but that would
    # lock the naming convention and someone might want to use
    # a meaningful example name.
    #
    build_one "console-hello"
    build_one "gui-hello"
    build_one "simple-text-editor"
    build_one "combo-box-example"
    #build_one "serial-comm"
}

echo "SCRIPT_DIR               $SCRIPT_DIR"
echo "EXAMPLES_DIR             $SCRIPT_DIR"
echo "BUILD_BASE_DIR           $BUILD_BASE_DIR"
echo "INSTALL_BASE_DIR         $INSTALL_BASE_DIR"
echo " "


while true; do
    read -p "Is this correct (Y/n)?" RESP
    case "${RESP:-Y}" in
        [""]* ) ;;
        [Yy]* ) echo "Yes"; break;;
        [Nn]* ) exit;;
	* ) echo "Please answer Y or n";;
    esac
done



while true; do
    read -p "Will you be using system installed LsCs or a local build (S/L)?" RESP
    case "${RESP:-L}" in
        [""]* ) ;;
        [sS]* ) echo "System"; local_build=false; break;;
        [Ll]* ) echo "Local build"; local_build=true; break;;
	* ) echo "Please answer S or L";;
    esac
done


if [ "$local_build" = true ] ; then


    if [ -z "${prefix_dir}"]; then
        prefix_dir="$PWD/../../LsCs_local_release/lib/LsCs/cmake"
    fi

    echo ""
    echo "using local build of: ${prefix_dir}"
    echo ""
    echo "if your local build is in a different location"
    echo "define the environment variable LsCs_DIR "
    echo "before running this script."
    echo ""

fi


while true; do
    echo " "
    echo "Build which example?"
    echo " "
    echo "1   - console based Hello World program"
    echo "2   - gui based Hello World program"
    echo "3   - simple text editor"
    echo "4   - combobox example"
    echo "5   - serial communications"
    echo "999 - build all"
    echo " "
    echo "e to exit"
    echo " "

    read -p "Please enter a number or e to exit: " RESP

    case "${RESP:-E}" in
        [""]* ) exit;;
        [1]* ) build_one "console-hello"; break;;
        [2]* ) build_one "gui-hello"; break;;
        [3]* ) build_one "simple-text-editor"; break;;
        [4]* ) build_one "combo-box-example"; break;;
        [5]* ) build_one "serial-comm"; break;;
        [999]*) build_all; exit;;
        [Ee]* ) exit;;
	* ) echo "Unknown response - please try again";;
    esac

done
