name: Build Tweak

on:
  push:
    branches: [ main ]
  workflow_dispatch:

jobs:
  build:
    runs-on: macos-latest
    
    steps:
    - uses: actions/checkout@v4
    
    - name: Install Theos
      run: |
        git clone --recursive https://github.com/theos/theos.git $THEOS
        echo "$THEOS/bin" >> $GITHUB_PATH
    
    - name: Build Tweak
      run: |
        make clean
        make package
    
    - name: Upload .deb
      uses: actions/upload-artifact@v4
      with:
        name: tweak-deb
        path: ./*.deb
