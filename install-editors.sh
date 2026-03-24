#!/bin/bash
#
#
# We use apostrophe to edit our markdown documentation like README.md
#

if [ `whoami` != root ]; then
    echo Please run this script as root or using sudo
    exit
fi

apt-get install jed jed-common jed-extra astyle hunspell meld emacs

add-apt-repository ppa:flatpak/stable
apt-get update

apt-get install flatpak
flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo

# We use apostrophe to edit our markdown documentation like README.md
#
flatpak install flathub org.gnome.gitlab.somas.Apostrophe
flatpak install flathub com.axosoft.GitKraken
