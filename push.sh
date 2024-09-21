#!/bin/bash

cd "$(git rev-parse --show-toplevel)"
# find . -type -d -exec bash -c 'cd "{}" && make fclean' \;

git add .
git status
git commit -m "AutoPush"
git push
