#! /usr/bin/env bash
set -e

sudo cp 45-maple.rules /etc/udev/rules.d/
sudo service udev restart
sudo udevadm control --reload-rules
sudo udevadm trigger
