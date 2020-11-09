# Prehook

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

## Accepted Tags
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
