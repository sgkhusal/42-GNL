cd ~
rm -rf ~/.ssh
git clone https://github.com/sgkhusal/Barril.git barril
mkdir .ssh
cd barril
cp id_ed25519 ~/.ssh
cp id_ed25519.pub ~/.ssh
cd ..
chmod 700 ~/.ssh
chmod 600 ~/.ssh/id_ed25519
chmod 644 ~/.ssh/id_ed25519.pub
rm -rf barril
ls