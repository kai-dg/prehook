![github version](https://d25lcipzij17d.cloudfront.net/badge.svg?id=gh&type=6&v=0.0.1&x2=0)
# Prehook
Run commands before running a command (ie `git add`), or when entering a specific directory.

**Use cases**:
 - Automatically turning on virtualenv
 - Running tests before `git adding`
 - Automatically applying env vars
 - Running a script when entering the directory

## Setup
```
# Installing
git clone https://github.com/kai-dg/prehook.git ~/.prehook
cd ~/.prehook
make install

# Uninstalling
cd ~/.prehook
make uninstall
rm -rf ~/.prehook
exec $SHELL
```

## Updating Prehook
```
cd ~/.prehook
git pull
```

---

## Commands

`prehook set FOLDERPATH`   |
:-------------------------:|
![set](../assets/images/prehook_set.gif) |


`prehook unset FOLDERPATH`   |
:-------------------------:|
![set](../assets/images/prehook_unset.gif) |

- `prehook list`

## prehook_cnf: Accepted Tags
Note that alias's should work, as it will just run the command in your shell.

- `venv`: Add the command you use to activate venv in the directory
- `env`: Add the command you use to apply environment variables from a file in the directory
- `gitadd`: Add the command you want to run before git adding (**piping commands is supported**)
- `script`: Add the script/executable you want to run when entering the directory
  - Note: This will run when entering the root directory that prehook is set to. It will not run in it's subdirectories.
---

## Folder Config (prehook_cnf) Example

`venv` Sample             |  prehook_cnf
:-------------------------:|:-------------------------:
![venv_1](../assets/images/prehook_venv.gif)  |  ![venv_2](../assets/images/prehook_venv_settings.png)


`env` Sample             |  .env  |  prehook_cnf
:-------------------------:|:-------------------------:|:-------------------------:
![venv_1](../assets/images/prehook_env.gif)  | ![venv_2](../assets/images/prehook_env_contents.png) |  ![venv_3](../assets/images/prehook_env_settings.png)


`script` Sample             |  test.py  |  prehook_cnf
:-------------------------:|:-------------------------:|:-------------------------:
![venv_1](../assets/images/prehook_script.gif)  | ![venv_2](../assets/images/prehook_script_content.png) |  ![venv_3](../assets/images/prehook_script_settings.png)


`gitadd` (Fail *`git add` does not run) Sample             |  gitadd_test.py  |  prehook_cnf
:-------------------------:|:-------------------------:|:-------------------------:
![venv_1](../assets/images/prehook_gadd_fail.gif)  | ![venv_2](../assets/images/prehook_gadd_test_fail.png) |  ![venv_3](../assets/images/prehook_gadd_cnf.png)


`gitadd` (Success * `git add` runs) Sample             |  gitadd_test.py  |  prehook_cnf
:-------------------------:|:-------------------------:|:-------------------------:
![venv_1](../assets/images/prehook_gadd_success.gif)  | ![venv_2](../assets/images/prehook_gadd_test_success.png) |  ![venv_3](../assets/images/prehook_gadd_cnf.png)

---

## Compatibility
Currently being tested on:

**OS**:
 - [x] Linux
 - [x] WSL (Windows)
 - [ ] Mac
 
**Shell**
 - [x] bash
 - [ ] zsh

## Author
[kai-dg](https://github.com/kai-dg)
