git init
git remote add origin https://github.com/jimboyeah/demo.git
git status
git branch -a
git remote show origin

git pull origin master
git pull origin OpenGL_demos
git checkout -b OpenGL_demos
git push origin OpenGL_demos:OpenGL_demos
rem git push [远程名] [本地分支]:[远程分支]
