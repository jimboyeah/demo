# Pacman 吃豆人

Pacman 经典吃豆人游戏，TypeScript 实现，未曾测试 IE 浏览器。

Pacman 作为经典游戏，其最有特色的部分就是带有 AI 原型的四个幽灵对手，资料：

- 红色的幽灵 Blinky 代表执着，它会一直跟着玩家走，并且随着玩家吃的豆越多移动速度会变的越快。
- 粉色的幽灵 Clyde 代表预知，它会以玩家路径的前方为目的地，经常会围堵玩家，官方的名称叫做“埋伏者”。
- 青色的幽灵 Linky 代表变化，它有时候会追着玩家走，有时候又会提前堵在玩家必经的路上，善于变化。
- 黄色的幽灵 Pinky 代表随意，它的行动路线完全随机，甚至大多数时间它会完全不理会玩家，一个人自己在地图上漫游。

更多参考资源：

<a href="https://www.googlepacman.net/">https://www.googlepacman.net/</a>
<a href="http://macek.github.io/google_pacman/">http://macek.github.io/google_pacman/</a>
<a href="https://passer-by.com/pacman/">https://passer-by.com/pacman/</a>

- [Play Online](https://jimboyeah.github.io/pacman/)
- [Pacman on Github](https://github.com/jimboyeah/demo/tree/packman)


# Git 命令参考：

    git init
    git remote remove origin
    git remote add origin https://github.com/jimboyeah/demos.git
    git status
    git branch -a
    git remote show origin

    git pull origin master
    git checkout -b pacman
    git push origin pacman:pacman
    git push [远程名] [本地分支]:[远程分支]


# Getting Started with Create React App


This project was bootstrapped with [Create React App](https://github.com/facebook/create-react-app).

## Available Scripts

In the project directory, you can run:

### `yarn start`

Runs the app in the development mode.\
Open [http://localhost:3000](http://localhost:3000) to view it in the browser.

The page will reload if you make edits.\
You will also see any lint errors in the console.

### `yarn test`

Launches the test runner in the interactive watch mode.\
See the section about [running tests](https://facebook.github.io/create-react-app/docs/running-tests) for more information.

    env: set PUBLIC_URL=http://localhost/   

see also: 

- [Advanced configuration](https://github.com/facebook/create-react-app/blob/master/docusaurus/docs/advanced-configuration.md)
- [Custom environment variables](https://github.com/facebook/create-react-app/blob/master/docusaurus/docs/adding-custom-environment-variables.md)

### `yarn build`

Builds the app for production to the `build` folder.\
It correctly bundles React in production mode and optimizes the build for the best performance.

The build is minified and the filenames include the hashes.\
Your app is ready to be deployed!

See the section about [deployment](https://facebook.github.io/create-react-app/docs/deployment) for more information.

### `yarn eject`

**Note: this is a one-way operation. Once you `eject`, you can’t go back!**

If you aren’t satisfied with the build tool and configuration choices, you can `eject` at any time. This command will remove the single build dependency from your project.

Instead, it will copy all the configuration files and the transitive dependencies (webpack, Babel, ESLint, etc) right into your project so you have full control over them. All of the commands except `eject` will still work, but they will point to the copied scripts so you can tweak them. At this point you’re on your own.

You don’t have to ever use `eject`. The curated feature set is suitable for small and middle deployments, and you shouldn’t feel obligated to use this feature. However we understand that this tool wouldn’t be useful if you couldn’t customize it when you are ready for it.

## Learn More

You can learn more in the [Create React App documentation](https://facebook.github.io/create-react-app/docs/getting-started).

To learn React, check out the [React documentation](https://reactjs.org/).
