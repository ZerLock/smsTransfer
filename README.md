# smsTransfer

This project aims to achieve automation. Initially, the transfer of SMS to emails, then extend this application to other services.

The goal is to run this program on a server, a raspberry-pi, in the background in order to let the automations do their work.

## Installation

The prerequisites are `C++` and `CMake`. If you do not have these two prerequisites the program will not be able to compile.

For installing dependencies, a bash script `install.sh` is there to install the necessary dependencies. This script is compatible with Macos (`brew` is required) and Linux (using `apt` package manager).

To install dependencies:

```bash
chmod +x install.sh
sudo ./install.sh
```

## Usage

To build the project, use `build.sh` file:

```bash
chmod +x build.sh
./build.sh <build_directory>
```

A binary called `smsTransfer` will be create and copy at the root of the folder.

_Here is the usage:_

```text
You must provide at least 1 service as command options

Usage:
  ./smsTransfer [SMS_REDIRECTION]
```

_Example:_

```bash
chmod +x smsTransfer
./smsTransfer SMS_REDIRECTION
```

Some services must use external equipment (like 4g-dongle with SIM card) to works.

Here is a list of external equipment necessaries to use each service:

| Service         | Equipment           |
| :-------------- | :------------------ |
| SMS_REDIRECTION | 4g-dongle, SIM card |
|                 |                     |

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](./LICENSE)
