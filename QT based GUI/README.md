# To create a complete GUI-based application, we will use Qt (for GUI), OpenSSL (for encryption), and C++17. 

## This application will:

    + Generate a serial key based on user input + hardware ID
    + Encrypt using AES-256 or RSA
    + Verify the serial key
    + Provide a Qt-based GUI


# Step 1: Install Dependencies
## Install Qt (for GUI)

    * Download Qt Creator from https://www.qt.io/download
    * Install with Qt 6.x or Qt 5.x

## Install OpenSSL

    * Linux: sudo apt install libssl-dev
    * Windows: Download OpenSSL binaries from https://slproweb.com/products/Win32OpenSSL.html

# Step 2: Create the Qt GUI Project

    * Open Qt Creator and create a Qt Widgets Application.
    * Save the project as SerialKeyGenerator.

# Step 3: GUI Layout (mainwindow.ui)

## Design the GUI:

    * QLineEdit: nameInput, emailInput, serialOutput
    * QPushButton: generateBtn, verifyBtn
    * QLabel: For messages

# Step 4: mainwindow.h

# Step 5: mainwindow.cpp

# Step 6: Build & Run

    1. Open Qt Creator
    2. Compile & Run the Project
    3. Enter Name & Email
    4. Generate & Save Serial Key
    5. Verify Key Against File

# Features Implemented

    + Qt GUI for User Input
    + Generates Serial Key from User & Hardware ID
    + Encrypts Key with AES
    + Verifies Serial Key

