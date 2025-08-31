# WasteOfSpace

#### `waste` is a simple command line tool that helps you waste space on your disk efficiently and conveniently.
# Usage
-  Waste 100mb of space on your disk:
```bash
waste 100
```
-  Specify the unit of space to waste (default is MB): 
```bash
waste 100 --unit GB
```
-  Access wasteful documentation:
```bash
# writing this wasted a lot of time
man waste
# reading it can waste yours too!
```
# Installation
#### Debian based system that use apt can install using the official [wasteofspace](https://zs-247.github.io/wasteofarepo/) repository
##### Non apt users can still install the project but will need to [compile from source](#to-build-and-install-from-source)
```bash
sudo mkdir -p /etc/apt/keyrings
curl -fsSL https://zs-247.github.io/wasteofarepo/repo.asc | sudo gpg --dearmor -o /etc/apt/keyrings/wasteofarepo.gpg
# add repository
echo "deb [signed-by=/etc/apt/keyrings/wasteofarepo.gpg] https://zs-247.github.io/wasteofarepo bookworm main" | sudo tee /etc/apt/sources.list.d/wasteofarepo.list
```
```bash
sudo apt update
sudo apt install waste
```
## To build and install from source:
-  Clone the repository:
```bash
git clone https://github.com/ZS-247/wasteofspace.git
```
-  Navigate to the project directory:
```bash
cd wasteofspace
```
- Install dependencies:
```bash
# On a debian based system like ubuntu or mint that uses apt:
sudo apt install make gcc
# On an arch based system:
sudo pacman -S make gcc
# On an opensuse based system:
sudo zypper install make gcc
# On a fedora based system:
sudo dnf install make gcc
# On a void based system:
sudo xbps-install make gcc

# freebsd should work out of the box, if not do:
sudo pkg install gmake gcc
# openbsd should also work out of the box, if not do:
doas pkg_add gmake gcc

# On a mac system the below should be sufficient:
xcode-select --install
# If not for macports do:
sudo port install gmake gcc15
sudo port select --set gcc mp-gcc15
# for homebrew do:
sudo brew install make gcc

# On a haiku system do:
pkgman install make gcc

# Your operating system may use a different package manager
```
- Build the project:
```bash
./configure && make
```
- Install the tool:
```bash
sudo make install
```
