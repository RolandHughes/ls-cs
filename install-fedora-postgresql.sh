#!/bin/bash
#
sudo dnf update -y
sudo dnf install postgresql postgresql-server
sudo postgresql-setup --initdb --unit postgresql
sudo systemctl enable --now postgresql

