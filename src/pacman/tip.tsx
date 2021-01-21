import React from 'react'

export default function tip() {
    return (
        <ul className="bb-custom-grid" id="bb-custom-grid">
          <li>
            <h3>提示</h3>
            <div className="bb-bookblock">
              <div className="bb-item">
                <p>Pacman 经典吃豆人游戏，TypeScript 实现，未曾测试 IE 浏览器。四个幽灵对手资料：
                红色的幽灵 Blinky 代表执着，它会一直跟着玩家走，并且随着玩家吃的豆越多移动速度会变的越快。
                粉色的幽灵 Clyde 代表预知，它会以玩家路径的前方为目的地，经常会围堵玩家，官方的名称叫做“埋伏者”。
                青色的幽灵 Linky 代表变化，它有时候会追着玩家走，有时候又会提前堵在玩家必经的路上，善于变化。
                黄色的幽灵 Pinky 代表随意，它的行动路线完全随机，甚至大多数时间它会完全不理会玩家，一个人自己在地图上漫游。
                更多参考资源：
                <a href="https://www.googlepacman.net/">https://www.googlepacman.net/</a>
                <a href="http://macek.github.io/google_pacman/">http://macek.github.io/google_pacman/</a>
                <a href="https://passer-by.com/pacman/">https://passer-by.com/pacman/</a>
                </p>
              </div>
            </div>
          </li>
          <li>
            <h3>选择</h3>
            <div className="bb-bookblock">
              <div className="bb-item">
              <a href="./pacman">Play Pacman</a>
              <a href="https://jimboyeah.github.io/pacman/">Play Online</a>
              <a href="https://github.com/jimboyeah/demo/tree/pacman">Github</a>
              </div>
            </div>
          </li>
        </ul>
    );
}
