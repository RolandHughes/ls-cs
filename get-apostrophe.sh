sudo add-apt-repository ppa:flatpak/stable
sudo apt update

sudo apt-get install flatpak
sudo flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo
sudo flatpak install apostrophe
