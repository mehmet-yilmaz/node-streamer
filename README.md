# Node-Streamer

Node streamer is a basic Gstreamer file converter.
This priject build to practise N-Api, node-addons-api Native C++ to NodeJS binding.

### Getting Started

- Install Prerequirements

    - git
    - build-essentials
    - cmake
    - pkg-config
    - gstreamer
    - nvm*
    - node

```

sudo apt install git build-essentials cmake pkg-config 
sudo apt install libgstreamer1.0-dev libgstreamer-plugins-base1.0-dev libgstreamer-plugins-bad1.0-dev gstreamer1.0-plugins-base gstreamer1.0-plugins-good gstreamer1.0-plugins-bad gstreamer1.0-plugins-ugly gstreamer1.0-libav gstreamer1.0-tools gstreamer1.0-x gstreamer1.0-alsa gstreamer1.0-gl gstreamer1.0-gtk3 gstreamer1.0-qt5 gstreamer1.0-pulseaudio
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.40.0/install.sh | bash
nvm install v20.17.0

```

- Clone the repository: 

```

git clone https://github.com/mehmet-yilmaz/node-streamer

```

- Open the folder

```

cd node-streamer

```

- Install the node dependencies

```

npm install

```


- Build C++ code 

```

node run build

```

- Copy the type defination file (.d.ts) from the `types` folder to the `./build/Release` folder

```

cp types/nodestreamer.d.ts ./build/Release/

```

- Compile Typescript code

```

tsc

```

- Run

```

node dist/main.js

```

