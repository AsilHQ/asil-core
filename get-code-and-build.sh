
# Clone the necessary repositories
git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git ~/depot_tools --depth=1
grep -qxF 'export PATH="$PATH:${HOME}/depot_tools"' ~/.bashrc || echo 'export PATH="$PATH:${HOME}/depot_tools"' >> ~/.bashrc
source ~/.bashrc

git clone -b 1.62 --depth=1000 https://github.com/AsilHQ/asil-core src/brave
cd src/brave

os_name="$(uname)"

# System-specific setup
if [ "$os_name" = "Darwin" ]; then
    sudo ln -s /usr/bin/python3 /usr/local/bin/python
elif [ "$os_name" = "Linux" ]; then
    ./build/install-build-deps.sh
else
    echo "Unsupported operating system: $os_name . Exiting without installing."
    exit 1
fi


caffeinate npm install
caffeinate npm run init
caffeinate npm run build
 npm start

