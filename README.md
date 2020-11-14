![github version](https://d25lcipzij17d.cloudfront.net/badge.svg?id=gh&type=6&v=0.0.1&x2=0)
# Prehook
Written for primarily people that live in the terminal, or vim/emacs/nano users. The primary concept is that the script in your profile (ie bashrc) is capable of running commands before and after a prompt command is entered. This allows for automatically turning on virtualenvs or exporting environment variables, as well as running tests/lints before hitting `git add`.

## Setup
```
git clone https://github.com/kai-dg/prehook.git ~/.prehook
cd ~/.prehook
make install
```

## Updating Prehook
```
cd ~/.prehook
git pull
```

---

## Commands

- `prehook set FOLDERPATH`

Example:

```
myfolder$ prehook set .
myfolder$ Prehook: Setting prehook to myfolder/
myfolder$ Prehook: Created prehook_cnf file.
```

## prehook_cnf: Accepted Tags
Note that alias's should work, as it will just run the command in your shell.

- `venv`: Add the command you use to activate venv in the folder
- `env`: Add the command you use to apply environment variables from a file
- `gitadd`: Coming soon

---

## Folder Config Example
```
# prehook_cnf
gitadd:npm run lint
venv:source venv/bin/activate
env:source .env
```

## Modifying tags
Check `tags.c` and `prehook_bash.c`

---

## Author
[kai-dg](https://github.com/kai-dg)
