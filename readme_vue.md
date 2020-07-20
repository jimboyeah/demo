# vue readme 前端框架
[Vue 官方网站](https://vuejs.org/)

[Vue.js 组件最佳实践](https://www.cnblogs.com/wenJiaQi/p/6528306.html)
[Vue.js Component Style Guide](https://pablohpsilva.github.io/vuejs-component-style-guide/#/)

[VueJS 开发常见问题集锦](https://segmentfault.com/a/1190000010230843)
[VueJS 开发常见问题集锦](https://blog.beard.ink/JavaScript/VueJS-开发常见问题集锦/)

[vuejs/awesome-vue: 🎉 A curated list of awesome things related to Vue.js](https://github.com/vuejs/awesome-vue)
[和 Vue.js 框架的作者聊聊前端框架开发背后的故事](http://teahour.fm/2015/08/16/vuejs-creator-evan-you.html)
[剖析 Vue.js 内部运行机制](https://juejin.im/book/5a36661851882538e2259c0f/section/5a37bbb35188257d167a4d64)
[Vue 虚拟 dom](https://zhuanlan.zhihu.com/p/68500937)
[Vue原理解析之Virtual Dom - Joe](https://segmentfault.com/a/1190000008291645)
[Vue.js 技术揭秘](https://github.com/ustbhuangyi/vue-analysis/tree/master/docs)


# Selenium & nightwatch 自动化测试
https://selenium.dev/
https://nightwatchjs.org/
https://segmentfault.com/a/1190000013259039
http://www.mamicode.com/info-detail-2430881.html
https://martinfowler.com/bliki/PageObject.html
https://www.cnblogs.com/jerryyj/p/9621542.html

Selenium 项目是一套非常流行且全面的浏览器自动化工具，最初是为Java编写的，但现在支持大多数编程语言。 

WebDriver 是一个用于自动化 Web 浏览器的通用库，作为 Selenium 项目的一部分。

WebDriver 现在是 W3C 规范，旨在标准化浏览器自动化。 WebDriver 是一个远程控制端口，可以对用户代理进行自我检查和控制。 它提供了一个平台以及静默 HTTP API，作为远程控制 Web 浏览器的一种方式。

Selenium 测试直接在浏览器中运行，就像真实用户所做的一样。Selenium 测试可以在 Windows、Linux 和 Macintosh上的 Internet Explorer、Chrome 和 Firefox 中运行。Selenium IDE 是一个 Firefox 插件，可以录制用户的基本操作，生成测试用例。随后可以运行这些测试用例在浏览器里回放，可将测试用例转换为其他语言的自动化脚本。Selenium 的核心 Selenium Core 基于 JsUnit，完全由JavaScript编写，因此可以用于任何支持 JavaScript 的浏览器上。 Selenium 可以模拟真实浏览器，自动化测试工具，支持多种浏览器，爬虫中主要用来解决 JavaScript 渲染问题。


安装 Python selenium 模块：

	pip install selenium

还有下载相应的 WebDriver

	https://npm.taobao.org/mirrors/chromedriver/
	https://npm.taobao.org/mirrors/geckodriver/
	https://npm.taobao.org/mirrors/operadriver/

Selenium 打开 Chrome 时，出现不受支持的命令行标记 –ignore-certificate-errors 则是因为 Chrome 和 chromedriver 版本不匹配。

以下 Python 脚本代码运行后，会自动打开 Chrome 浏览器，并登陆百度打印百度首页的源代码，然后关闭浏览器

	from selenium import webdriver
	browser = webdriver.Chrome()
	url = 'https://www.baidu.com'
	browser.get(url)
	print(browser.page_source)
	browser.close()

这里我们通过2种不同的方式去获取响应的元素，第一种是通过id的方式，第二个中是CSS选择器，结果都是相同的。

	from selenium import webdriver
	browser = webdriver.Chrome()
	url = 'https://www.taobao.com'
	browser.get(url)
	input_first = browser.find_element_by_id('q')
	input_two = browser.find_element_by_css_selector('#q')
	print(input_first)
	print(input_two)

对于获取的元素调用交互方法

	from selenium import webdriver
	import time
	browser = webdriver.Chrome()
	browser.get(url='https://www.baidu.com')
	time.sleep(2)
	input = browser.find_element_by_css_selector('#kw')
	input.send_keys('韩国女团')
	time.sleep(2)
	input.clear()
	input.send_keys('后背摇')
	button = browser.find_element_by_css_selector('#su')
	button.click()
	time.sleep(10)
	browser.close()

将动作附加到动作链中串行执行
	
	from selenium import webdriver
	from selenium.webdriver import ActionChains
	
	browser = webdriver.Chrome()
	
	url = "http://www.runoob.com/try/try.php?filename=jqueryui-api-droppable"
	browser.get(url)
	browser.switch_to.frame('iframeResult')
	source = browser.find_element_by_css_selector('#draggable')
	target = browser.find_element_by_css_selector('#droppable')
	actions = ActionChains(browser)
	actions.drag_and_drop(source, target)
	actions.perform()

执行 JavaScript 是一个非常有用的方法，下面的例子是通过脚本翻到页面底部，并弹框提示

	from selenium import webdriver
	import time

	browser = webdriver.Chrome()
	url = 'https://www.jianshu.com/p/b8bb08229904'
	browser.get(url)
	browser.execute_script('window.scrollTo(0,document.body.scrollHeight)')
	browser.execute_script('alert("To Bottom")')
	time.sleep(5)
	#browser.close()

在 selenium-webdriver 中等待页面加载有两种方式进行，明确的等待和隐性的等待，利用 WebDriverWait 类和 ExpectedCondition 接口等待恰当的时间。

	from selenium import webdriver
	import time

	browser = webdriver.Chrome()
	browser.get(url='http://192.168.0.105:8080/')
	time.sleep(2) # wait page loading
	input = browser.find_element_by_css_selector('input[type=search]')
	input.send_keys('web automation test')
	input.clear()
	input.send_keys('Selenium & Nightwatch')
	button = browser.find_element_by_css_selector('button[type=submit]')
	button.click()
	print("do click...")
	# browser.close()


Nightwatch.js 是一个用于 Web 应用程序和网站的自动化测试框架，使用 Node.js 编写并使用 W3C WebDriver API，以前称为 Selenium WebDriver。它是一个完整的浏览器测试解决方案，旨在简化设置持续集成和编写自动化测试的过程。 Nightwatch 也可用于编写 Node.js 单元测试。

Nightwatch 使用 WebDriver API 执行与浏览器自动化相关的任务，例如打开窗口和单击链接。

Nightwatch 通过与 WebDriver 服务器通常是 Selenium 服务器，通过静默 HTTP API 进行通信。

大多数情况下，Nightwatch 需要向 WebDriver 服务器发送至少 2 个请求才能执行命令或断言，第一个请求是在给定 CSS 选择器或 Xpath 表达式定位元素，然后执行下一个请求给定元素上的实际命令/断言。

首先在项目里面安装 nightwatch 和 selenium-server

	npm install nightwatch -D
	npm install selenium-server -D

selenium-server 是基于 Java 开发的，作用是用来连接浏览器的。所以安装 selenium-server 之前需要安装 Java。

除此之外还需要安装一个浏览器驱动器，一般我们使用 chrome 做测试

	npm install chromedriver --chromedriver_cdnurl=http://cdn.npm.taobao.org/dist/chromedrive -D

	npm install geckodriver chromedriver nightwatch -D

nightwatch 优先使用项目根目录的 nightwatch.conf.js 作为配置文件，其次使用 nightwatch.json。nightwatch.conf.js 方便使用 JavaScript 动态生成配置信息。如果配置信息是不需要代码修改的，直接使用 nightwatch.json 就可以啦。

下面这个就是一个简单的配置文件，参考 nightwatch\examples 目录。

	module.exports = {
	    'src_folders': [
	        'e2e/case'
	    ],
	    'output_folder': 'reports',
	    'custom_commands_path': '',
	    'custom_assertions_path': '',
	    'page_objects_path': '',
	    'globals_path': require('./e2e/config/global.config').path,
	    'selenium': {
	        'start_process': true,
	        'server_path': require('selenium-server').path,
	        'log_path': '',
	        'host': '127.0.0.1',
	        'port': 4444,
	        'cli_args': {
	            'webdriver.chrome.driver': require('chromedriver').path
	        }
	    },
	    'test_settings': {
	        'default': {
	            'launch_url': 'http://localhost',
	            'selenium_port': 4444,
	            'selenium_host': 'localhost',
	            'silent': true,
	            'screenshots': {
	                'enabled': false,
	                'path': ''
	            },
	            'desiredCapabilities': {
	                'browserName': 'chrome',
	                'marionette': true
	            }
	        },
	        'chrome': {
	            'desiredCapabilities': {
	                'browserName': 'chrome'
	            }
	        },
	        'edge': {
	            'desiredCapabilities': {
	                'browserName': 'MicrosoftEdge'
	            }
	        }
	    }
	}

- src_folders 表示的就是case所在的文件夹
- output_folder 代表的是报告输出的文件夹
- selenium 
	- server_path 代表的是 selenium-server 的安装路径
	- start_process 代表的是是否自动启动 selenium-server，默认 false 不会自动启动 server。
	- cli_args 
		- driver 表示 driver 的安装路径，分别安装成功就可以了
- test_settings 是传给 nightwatch 实例的数据，这里面可以配置多个环境，default是必须有的，其他环境可以自行配制。

现在 case 文件夹下面创建一些 case：

	module.exports = {
	    'Test login': function (browser) {
	        browser
	            .windowMaximize()
	            .url('https://trans.qa.17u.cn/saas')
	            .waitForElementVisible('.login', 3000)
	            .assert.urlContains('/saas/login')
	    }
	    
	}

	module.exports = {

	  before : function(browser) { ... },
	  after : function(browser) { ... },
	  beforeEach : function(browser) { ... },
	  afterEach : function() { ... },

	  'Demo test Ecosia.org': function (browser) {
	    browser
	      .url('https://www.ecosia.org/')
	      .waitForElementVisible('body')
	      .assert.titleContains('Ecosia')
	      .assert.visible('input[type=search]')
	      .setValue('input[type=search]', 'nightwatch')
	      .assert.visible('button[type=submit]')
	      .click('button[type=submit]')
	      .assert.containsText('.home', 'Home')
	      .end();
	  }
	};

执行测试：

在项目目录中建立 startup.js 文件，并写下一下代码：

	require(‘nightwatch/bin/runner.js‘)

这是启动命令，我们只需要在控制台输入 node ./startup 就可以执行，但是我建议用 npm 命令来执行，配置 package.json 文件 scripts 里添加：

	"nightwatch": "node ./startup.js"

以后要开启测试的时候就直接输入 npm nightwatch 命令就可以了，在 package.json 配置一下脚本，其中任意一条都可以：

	"scripts": {
	    "nw": "node node_modules\\nightwatch\\bin\\runner.js --env chrome",
	    "nightwatch": "nightwatch --env chrome",
	},

测试结果实例：

	$ npm run nightwatch

	> vue3rd@0.1.0 nightwatch C:\coding\md-code\vue-3.0
	> nightwatch --env chrome


	[Case] Test Suite
	=================
	\ Connecting to localhost on port 9515...

	i Connected to localhost on port 9515 (4613ms).
	  Using: chrome (79.0.3945.88) on Windows platform.

	Running:  Demo test

	√ Element <body> was visible after 45 milliseconds.
	√ Testing if the page title contains 'vue3rd' (10ms)
	√ Element <.home> was visible after 34 milliseconds.
	√ Testing if the URL contains '/' (13ms)
	√ Testing if element <input[type=search]> is visible (33ms)
	√ Testing if element <button[type=submit]> is visible (25ms)
	√ Testing if element <.home> contains text 'Home' (33ms)

	OK. 7 assertions passed. (1.102s)




# Vue 3.0 官方文档

Vue 3.0 官方文档 https://cli.vuejs.org/zh/guide/	
https://github.com/vuejs/vue-cli/blob/master/docs/zh/guide/

## Vue 3.0 Installation

::: warning 关于旧版本 Vue CLI 的包名称由 vue-cli 改成了 @vue/cli。 如果你已经全局安装了旧版本的 vue-cli (1.x 或 2.x)，你需要先通过 npm uninstall vue-cli -g 或 yarn global remove vue-cli 卸载它。 :::

::: tip Node 版本要求 Vue CLI 需要 Node.js 8.9 或更高版本 (推荐 8.11.0+)。你可以使用 nvm 或 nvm-windows 在同一台电脑中管理多个 Node 版本。 :::

可以使用下列任一命令安装这个新的包：

	npm install -g @vue/cli
	# OR
	yarn global add @vue/cli

安装之后，你就可以在命令行中访问 vue 命令。你可以通过简单运行 vue，看看是否展示出了一份所有可用命令的帮助信息，来验证它是否安装成功。

你还可以用这个命令来检查其版本是否正确：

	vue --version

使用 @vue/cli 脚手架：

	vue create my-project


## 介绍

::: warning 警告
这份文档是对应 `@vue/cli`。老版本的 `vue-cli` 文档请移步[这里](https://github.com/vuejs/vue-cli/tree/v2#vue-cli--)。
:::

Vue CLI 是一个基于 Vue.js 进行快速开发的完整系统，提供：

- 通过 `@vue/cli` 搭建交互式的项目脚手架。
- 通过 `@vue/cli` + `@vue/cli-service-global` 快速开始零配置原型开发。
- 一个运行时依赖 (`@vue/cli-service`)，该依赖：
  - 可升级；
  - 基于 webpack 构建，并带有合理的默认配置；
  - 可以通过项目内的配置文件进行配置；
  - 可以通过插件进行扩展。
- 一个丰富的官方插件集合，集成了前端生态中最好的工具。
- 一套完全图形化的创建和管理 Vue.js 项目的用户界面。

Vue CLI 致力于将 Vue 生态中的工具基础标准化。它确保了各种构建工具能够基于智能的默认配置即可平稳衔接，这样你可以专注在撰写应用上，而不必花好几天去纠结配置的问题。与此同时，它也为每个工具提供了调整配置的灵活性，无需 eject。

Vue CLI 有几个独立的部分——如果你看到了我们的[源代码](https://github.com/vuejs/vue-cli/tree/dev/packages/%40vue)，你会发现这个仓库里同时管理了多个单独发布的包。

### CLI

CLI (`@vue/cli`) 是一个全局安装的 npm 包，提供了终端里的 `vue` 命令。它可以通过 `vue create` 快速创建一个新项目的脚手架，或者直接通过 `vue serve` 构建新想法的原型。你也可以通过 `vue ui` 通过一套图形化界面管理你的所有项目。我们会在接下来的指南中逐章节深入介绍。

### CLI 服务

CLI 服务 (`@vue/cli-service`) 是一个开发环境依赖。它是一个 npm 包，局部安装在每个 `@vue/cli` 创建的项目中。

CLI 服务是构建于 [webpack](http://webpack.js.org/) 和 [webpack-dev-server](https://github.com/webpack/webpack-dev-server) 之上的。它包含了：

- 加载其它 CLI 插件的核心服务；
- 一个针对绝大部分应用优化过的内部的 webpack 配置；
- 项目内部的 `vue-cli-service` 命令，提供 `serve`、`build` 和 `inspect` 命令。

如果你熟悉 [create-react-app](https://github.com/facebookincubator/create-react-app) 的话，`@vue/cli-service` 实际上大致等价于 `react-scripts`，尽管功能集合不一样。

[CLI 服务](./cli-service.md)章节涵盖了它的具体用法。

### CLI 插件

CLI 插件是向你的 Vue 项目提供可选功能的 npm 包，例如 Babel/TypeScript 转译、ESLint 集成、单元测试和 end-to-end 测试等。Vue CLI 插件的名字以 `@vue/cli-plugin-` (内建插件) 或 `vue-cli-plugin-` (社区插件) 开头，非常容易使用。

当你在项目内部运行 `vue-cli-service` 命令时，它会自动解析并加载 `package.json` 中列出的所有 CLI 插件。

插件可以作为项目创建过程的一部分，或在后期加入到项目中。它们也可以被归成一组可复用的 preset。我们会在[插件和 preset](./plugins-and-presets.md) 章节进行深入讨论。



## prototyping 快速原型开发

你可以使用 `vue serve` 和 `vue build` 命令对单个 `*.vue` 文件进行快速原型开发，不过这需要先额外安装一个全局的扩展：

``` bash
npm install -g @vue/cli-service-global
# OR
yarn global add @vue/cli-service-global
```

`vue serve` 的缺点就是它需要安装全局依赖，这使得它在不同机器上的一致性不能得到保证。因此这只适用于快速原型开发。

### vue serve

```
Usage: serve [options] [entry]

在开发环境模式下零配置为 .js 或 .vue 文件启动一个服务器


Options:

  -o, --open  打开浏览器
  -c, --copy  将本地 URL 复制到剪切板
  -h, --help  输出用法信息
```

你所需要的仅仅是一个 `App.vue` 文件：

``` vue
<template>
  <h1>Hello!</h1>
</template>
```

然后在这个 `App.vue` 文件所在的目录下运行：

``` bash
vue serve
```

`vue serve` 使用了和 `vue create` 创建的项目相同的默认设置 (webpack、Babel、PostCSS 和 ESLint)。它会在当前目录自动推导入口文件——入口可以是 `main.js`、`index.js`、`App.vue` 或 `app.vue` 中的一个。你也可以显式地指定入口文件：

``` bash
vue serve MyComponent.vue
```

如果需要，你还可以提供一个 `index.html`、`package.json`、安装并使用本地依赖、甚至通过相应的配置文件配置 Babel、PostCSS 和 ESLint。

### vue build

```
Usage: build [options] [entry]

在生产环境模式下零配置构建一个 .js 或 .vue 文件


Options:

  -t, --target <target>  构建目标 (app | lib | wc | wc-async, 默认值：app)
  -n, --name <name>      库的名字或 Web Components 组件的名字 (默认值：入口文件名)
  -d, --dest <dir>       输出目录 (默认值：dist)
  -h, --help             输出用法信息
```

你也可以使用 `vue build` 将目标文件构建成一个生产环境的包并用来部署：

``` bash
vue build MyComponent.vue
```

`vue build` 也提供了将组件构建成为一个库或一个 Web Components 组件的能力。查阅[构建目标](./build-targets.md)了解更多。


## 创建一个项目

### vue create

运行以下命令来创建一个新项目：

``` bash
vue create hello-world
```

::: warning 警告
如果你在 Windows 上通过 minTTY 使用 Git Bash，交互提示符并不工作。你必须通过 `winpty vue.cmd create hello-world` 启动这个命令。不过，如果你仍想使用 `vue create hello-world`，则可以通过在 `~/.bashrc` 文件中添加以下行来为命令添加别名。
`alias vue='winpty vue.cmd'`
你需要重新启动 Git Bash 终端会话以使更新后的 bashrc 文件生效。
:::

你会被提示选取一个 preset。你可以选默认的包含了基本的 Babel + ESLint 设置的 preset，也可以选“手动选择特性”来选取需要的特性。

![CLI 预览](/cli-new-project.png)

这个默认的设置非常适合快速创建一个新项目的原型，而手动设置则提供了更多的选项，它们是面向生产的项目更加需要的。

![CLI 预览](/cli-select-features.png)

如果你决定手动选择特性，在操作提示的最后你可以选择将已选项保存为一个将来可复用的 preset。我们会在下一个章节讨论 preset 和插件。

::: tip ~/.vuerc
被保存的 preset 将会存在用户的 home 目录下一个名为 `.vuerc` 的 JSON 文件里。如果你想要修改被保存的 preset / 选项，可以编辑这个文件。

在项目创建的过程中，你也会被提示选择喜欢的包管理器或使用[淘宝 npm 镜像源](https://npm.taobao.org/)以更快地安装依赖。这些选择也将会存入 `~/.vuerc`。
:::

`vue create` 命令有一些可选项，你可以通过运行以下命令进行探索：

``` bash
vue create --help
```

```
用法：create [options] <app-name>

创建一个由 `vue-cli-service` 提供支持的新项目


选项：

  -p, --preset <presetName>       忽略提示符并使用已保存的或远程的预设选项
  -d, --default                   忽略提示符并使用默认预设选项
  -i, --inlinePreset <json>       忽略提示符并使用内联的 JSON 字符串预设选项
  -m, --packageManager <command>  在安装依赖时使用指定的 npm 客户端
  -r, --registry <url>            在安装依赖时使用指定的 npm registry
  -g, --git [message]             强制 / 跳过 git 初始化，并可选的指定初始化提交信息
  -n, --no-git                    跳过 git 初始化
  -f, --force                     覆写目标目录可能存在的配置
  -c, --clone                     使用 git clone 获取远程预设选项
  -x, --proxy                     使用指定的代理创建项目
  -b, --bare                      创建项目时省略默认组件中的新手指导信息
  -h, --help                      输出使用帮助信息
```

### 使用图形化界面

你也可以通过 `vue ui` 命令以图形化界面创建和管理项目：

``` bash
vue ui
```

上述命令会打开一个浏览器窗口，并以图形化界面将你引导至项目创建的流程。

![图形化界面预览](/ui-new-project.png)

### 拉取 2.x 模板 (旧版本)

Vue CLI >= 3 和旧版使用了相同的 `vue` 命令，所以 Vue CLI 2 (`vue-cli`) 被覆盖了。如果你仍然需要使用旧版本的 `vue init` 功能，你可以全局安装一个桥接工具：

``` bash
npm install -g @vue/cli-init
# `vue init` 的运行效果将会跟 `vue-cli@2.x` 相同
vue init webpack my-project
```



## CLI 服务 cli-service

### 使用命令

在一个 Vue CLI 项目中，`@vue/cli-service` 安装了一个名为 `vue-cli-service` 的命令。你可以在 npm scripts 中以 `vue-cli-service`、或者从终端中以 `./node_modules/.bin/vue-cli-service` 访问这个命令。

这是你使用默认 preset 的项目的 `package.json`：

``` json
{
  "scripts": {
    "serve": "vue-cli-service serve",
    "build": "vue-cli-service build"
  }
}
```

你可以通过 npm 或 Yarn 调用这些 script：

``` bash
npm run serve
## OR
yarn serve
```

如果你可以使用 [npx](https://github.com/npm/npx) (最新版的 npm 应该已经自带)，也可以直接这样调用命令：

``` bash
npx vue-cli-service serve
```

::: tip 提示
你可以通过 `vue ui` 命令使用 GUI 运行更多的特性脚本。
:::

这里有一个 GUI 的 webpack Analyzer：

![UI webpack Analyzer](/ui-analyzer.png)

### vue-cli-service serve

```
用法：vue-cli-service serve [options] [entry]

选项：

  --open    在服务器启动时打开浏览器
  --copy    在服务器启动时将 URL 复制到剪切版
  --mode    指定环境模式 (默认值：development)
  --host    指定 host (默认值：0.0.0.0)
  --port    指定 port (默认值：8080)
  --https   使用 https (默认值：false)
```

`vue-cli-service serve` 命令会启动一个开发服务器 (基于 [webpack-dev-server](https://github.com/webpack/webpack-dev-server)) 并附带开箱即用的模块热重载 (Hot-Module-Replacement)。

除了通过命令行参数，你也可以使用 `vue.config.js` 里的 [devServer](../config/#devserver) 字段配置开发服务器。

命令行参数 `[entry]` 将被指定为唯一入口，而非额外的追加入口。尝试使用 `[entry]` 覆盖 `config.pages` 中的 `entry` 将可能引发错误。

### vue-cli-service build

```
用法：vue-cli-service build [options] [entry|pattern]

选项：

  --mode        指定环境模式 (默认值：production)
  --dest        指定输出目录 (默认值：dist)
  --modern      面向现代浏览器带自动回退地构建应用
  --target      app | lib | wc | wc-async (默认值：app)
  --name        库或 Web Components 模式下的名字 (默认值：package.json 中的 "name" 字段或入口文件名)
  --no-clean    在构建项目之前不清除目标目录
  --report      生成 report.html 以帮助分析包内容
  --report-json 生成 report.json 以帮助分析包内容
  --watch       监听文件变化
```

`vue-cli-service build` 会在 `dist/` 目录产生一个可用于生产环境的包，带有 JS/CSS/HTML 的压缩，和为更好的缓存而做的自动的 vendor chunk splitting。它的 chunk manifest 会内联在 HTML 里。

这里还有一些有用的命令参数：

- `--modern` 使用[现代模式](./browser-compatibility.md#现代模式)构建应用，为现代浏览器交付原生支持的 ES2015 代码，并生成一个兼容老浏览器的包用来自动回退。

- `--target` 允许你将项目中的任何组件以一个库或 Web Components 组件的方式进行构建。更多细节请查阅[构建目标](./build-targets.md)。

- `--report` 和 `--report-json` 会根据构建统计生成报告，它会帮助你分析包中包含的模块们的大小。

### vue-cli-service inspect

```
用法：vue-cli-service inspect [options] [...paths]

选项：

  --mode    指定环境模式 (默认值：development)
```

你可以使用 `vue-cli-service inspect` 来审查一个 Vue CLI 项目的 webpack config。更多细节请查阅[审查 webpack config](./webpack.md#审查项目的-webpack-config)。

### 查看所有的可用命令

有些 CLI 插件会向 `vue-cli-service` 注入额外的命令。例如 `@vue/cli-plugin-eslint` 会注入 `vue-cli-service lint` 命令。你可以运行以下命令查看所有注入的命令：

``` bash
npx vue-cli-service help
```

你也可以这样学习每个命令可用的选项：

``` bash
npx vue-cli-service help [command]
```

### 缓存和并行处理

- `cache-loader` 会默认为 Vue/Babel/TypeScript 编译开启。文件会缓存在 `node_modules/.cache` 中——如果你遇到了编译方面的问题，记得先删掉缓存目录之后再试试看。

- `thread-loader` 会在多核 CPU 的机器上为 Babel/TypeScript 转译开启。

### Git Hook

在安装之后，`@vue/cli-service` 也会安装 [yorkie](https://github.com/yyx990803/yorkie)，它会让你在 `package.json` 的 `gitHooks` 字段中方便地指定 Git hook：

``` json
{
  "gitHooks": {
    "pre-commit": "lint-staged"
  },
   "lint-staged": {
    "*.{js,vue}": [
      "vue-cli-service lint",
      "git add"
    ]
  }
}
```

::: warning
`yorkie` fork 自 [`husky`](https://github.com/typicode/husky) 且并与后者不兼容。
:::

### 配置时无需 Eject

通过 `vue create` 创建的项目无需额外的配置就已经可以跑起来了。插件的设计也是可以相互共存的，所以绝大多数情况下，你只需要在交互式命令提示中选取需要的功能即可。

不过我们也知道满足每一个需求是不太可能的，而且一个项目的需求也会不断改变。通过 Vue CLI 创建的项目让你无需 eject 就能够配置工具的几乎每个角落。更多细节请查阅[配置参考](../config/)。






# Vue 3.0 尝鲜
《Vue 3.0 抢先学》系列 https://www.jianshu.com/p/51dc95aa6eea

Vue 3.0的源码终于出现在了Github的Vue官方项目仓库中 https://github.com/vuejs/vue-next/ 当前版本处于 Pre Alpha 状态。

	git clone https://github.com/vuejs/vue-next.git

其中几个比较重要的模块，先作一下简要的介绍：

- vue Vue项目的主入口模块
- reactivity 非常重要的模块，实现Vue3.0的数据响应式功能的核心
- compiler-core 模板核心语法编译器，包括对标签、属性、指令（如v-if、v-for、v-bind、v-model、v-on、v-once、v-slot等）模板语法的解析
- compiler-dom Vue模板编译器，可编译模板中其他功能性指令（如v-clock、v-html、v-text等）。依赖compiler-core
- runtime-core 实现虚拟DOM、组件定义、生命周期、指令定义、依赖注入、渲染等功能的核心模块
- runtime-dom Vue浏览器DOM环境运行时，负责实现与浏览器环境运行所需的相关特性。依赖 runtime-core

其中还有些模块尚未开发完成，比如做服务端渲染（SSR）的server-renderer模块。

初步了解了工程结构后，我还是花了不少的时间阅读了一些关键性的代码文件及单元测试，收获还是不小，也澄清了之前的一些疑问，大致如下：

1. Vue3.0是一个全新的框架？Vue2.x的程序迁移到Vue3.0会比较困难？
不可否认，如果说从框架的实现层面来说，Vue3.0确实是一个全新的框架，框架的代码实现全部采用了TypeScript来编写，并且引入了一种和之前完全不同写法的API：组合式API（Composition API）的接口函数，但是对于框架的使用者来说（使用Vue3.0开发自己应用的开发者），你以前的写法仍然工作，Vue3.0提供了向下兼容，使得老项目的迁移变得更容易。

2. Vue3.0的响应式是采用的Proxy么？
是的，新版框架的数据响应式核心组件不再使用Vue2.x时所采用的Object.defineProperty()方式来对数据变化进行跟踪和触发，而是采用了更高级的Proxy，据说拥有更好的性能，以及可以更好的支持对数组元素进行响应式处理，一扫Vue2.x在这方面的尴尬场面。不过，值得注意的是，绝大多数版本的IE浏览器是不支持Proxy的，如果需要进行兼容，我们可能需要引入相关polyfill。

3. 一定要用TypeScript来编写代码？
不是。框架构建后生成的是js文件，你还是可以像以前一样使用Vue，比如直接在HTML文件中通过 `<script>` 标签来引入 vue.global.js 文件；也可以在通过vue-cli生成的单页应用项目中通过引入模块的形式来导入（import）Vue框架；你可以根据你的喜好和具体使用场景，来合理选用js、jsx、ts、tsx进行代码的编写。

4. 可以写出像React风格的组件代码吗？
可以。通过采用jsx或tsx，结合使用render()函数和Composition API，我们完全可以写出很漂亮的函数式风格Vue代码。

## Vue 3.0 demo

让我们这就来试一试，赶紧开始编译一下框架源代码，命令行咔咔敲起来！

	# 安装项目的依赖包
	yarn             #如果你用的是 yarn
	npm install      #如果你用的是 npm

	# 构建出可发布代码
	yarn build       #如果你用的是 yarn
	npm run build    #如果你用的是 npm

经过几十秒炫酷的命令行刷屏之后，构建完成了。之后，我们可以看到在packages下的各个子项目文件夹中，有已经生成好的dist目录，里面躺着几个文件，命名不太一样，有的文件名中有prod后缀，有的则没有，这个代表经过压缩的或不压缩的js；有的包含了global、cjs、esm-xxx等，这个则表示这个js文件适用的模块加载器类型。我们可以按照实际需要来选用。


我下面将选用 packages/vue/dist 目录下的 vue.global.prod.js 这个文件，因为它是打包后得到的最完整的框架代码，可以直接通过`<script>`标签引入HTML页面，最适合我用来快速编写示例代码。

下面我要用 Vue3.0 来编写一个简单的鼠标点击计数器。

开始写代码咯，让我来先初始化一下我的示例项目：建一个文件夹，下面的文件结构如下图所示，有css和js目录，分别存放示例代码要用到的样式、vue的js库文件、以及我们编写的示例js代码文件；而 index.html 则就是这个程序的主入口了。

	<!DOCTYPE html>
	<html lang="en">

	<head>
	    <meta charset="UTF-8">
	    <meta name="viewport" content="width=device-width, initial-scale=1.0">
	    <meta http-equiv="X-UA-Compatible" content="ie=edge">
	    <title>Vue3.0 Demo</title>
	    <link rel="stylesheet" type="text/css" href="./css/main.css" />
	    <style>
			.container {
			    border: 1px solid #cccccc;
			    border-radius: 5px;
			    width: 250px;
			    padding: 20px;
			}

			.counter-display {
			    margin-bottom: 20px;
			}

			.counter-text {
			    font-size: 18px;
			    font-weight: bold;
			    color: #ff9900;
			    margin: 0 5px;
			}

			.counter-btns .btn {
			    border: 1px solid #cccccc;
			    border-radius: 5px;
			    width: 80px;
			    height: 40px;
			    outline: none;
			    background: #f2f2f2;
			    margin-right: 10px;
			}
	    </style>
	</head>

	<body>
	    <!-- 应用挂载点元素 -->
	    <div id="app"></div>

	    <!-- 引入Vue3.0库文件 -->
	    <script src="./js/lib/vue.global.prod.js"></script>

	    <!-- 我们的应用代码 -->
	    <script>
			const { createApp, createComponent } = Vue

			// 计数器组件
			const Counter = createComponent({
			    template: `
			        <div class="counter-display">
			            <span class="counter-label">恭喜你，你已经写了</span>
			            <span class="counter-text">{{ count }}</span>
			            <span class="counter-label">斤代码！</span>
			        </div>
			        <div class="counter-btns">
			            <button class="btn" @click="increase">写一斤</button>
			            <button class="btn" @click="reset">删库啦</button>
			        </div>
			    `,

			    data() {
			        return {
			            count: 0
			        }
			    },

			    methods: {
			        increase() {
			            this.count++;
			        },
			        reset() {
			            this.count = 0;
			        }
			    }
			})

			// 根组件
			const App = createComponent({
			    components: { Counter },
			    template: `
			        <div class="container">
			            <h3>计数器示例</h3>
			            <Counter />
			        </div>
			    `
			})

			// 启动
			const container = document.querySelector('#app')
			const app = createApp()

			app.mount(App, container)
	    </script>
	</body>

	</html>

这几乎是和 2.x 的代码一模一样的，除了 `createApp()`、`createComponent()` 函数稍稍有点不同。其实，这里的`createComponent()`函数也不是必须的，完全可以去掉，它的存在是为了当我们使用 TypeScript 编写代码时，利用 TypeScript 的类型推断机制在开发工具里（如VSCode）实现更好的参数自动提示功能。

所以呢，写成下面这样也是完全可以工作的：

	const App = {
	    components: { Counter },
	    template: `
	        <div class="container">
	            <h3>计数器示例</h3>
	            <Counter />
	        </div>
	    `
	}



## Ref vs. Reactive

在上文中，我们使用Vue3.0最新的Composition API改写了由Options API写成的计数器示例。我们发现，原先的数据响应式监听的用法发生了变化，原先通过data中声明的响应式属性，现在替换成由 ref 函数来创建：

	// Vue2.x Options API 写法
	data() {
	  return {
	    count: 0
	  }
	}

	// Vue3.x Composition API 写法
	const count = ref(0)

这种新的写法，有点React Hooks的味道了。ref 函数传入一个值作为参数，返回一个基于该值的响应式Ref对象，该对象中的值一旦被改变和访问，都会被跟踪到，就像我们改写后的示例代码一样，通过修改 count.value 的值，可以触发模板的重新渲染，显示最新的值。

其实，除了 ref 函数，Vue3.0中还提供了另外一个可以创建响应式对象的函数，那就是 reactive 函数。如果我们的示例程序用 reactive 函数来改写，那么会是这样子的：

	const { createApp, reactive } = Vue

	// 计数器组件
	const Counter = {
	    template: `
	        <div class="counter-display">
	            <span class="counter-label">恭喜你，你已经写了</span>
	            <span class="counter-text">{{ state.count }}</span>
	            <span class="counter-label">斤代码！</span>
	        </div>
	        <div class="counter-btns">
	            <button class="btn" @click="increase">写一斤</button>
	            <button class="btn" @click="reset">删库啦</button>
	        </div>
	    `,

	    setup() {
	        const countOps = useCount()
	        return { ...countOps }
	    }
	}

	function useCount() {
	    const state = reactive({ count: 0 })
	    const increase = () => { state.count++ }
	    const reset = () => { state.count = 0 }
	    return { state, increase, reset }
	}
	和使用 ref 的时候变化不是很大，只是把 count 作为一个对象的属性进行包装了，看起来是不是也很容易理解？

	然而，你可能会有疑问，为什么要提供 ref 和 reactive 两种方式呢？其实，这是和为了适应不同人的编程风格有关。要理解这点，让我们先来看2段实现了同样功能的代码。

	风格一：

	let x = 0
	let y = 0

	function updatePos(e) {
	  x = e.pageX
	  y = e.pageY
	}
	风格二：

	const pos = { x: 0, y: 0 }

	function updatePos(e) {
	  pos.x = e.pageX
	  pos.y = e.pageY
	}
	从上面的2段代码观察到，两者的主要区别在于：风格一，我们使用了2个变量来存储x、y坐标值；而风格二则将x、y值封装于一个对象的2个属性中存储。这两种风格的代码工作的都没问题，关键在于个人或团队的偏好：使用单独的变量还是使用对象封装。

	而前面说的 ref 和 reactive 的区别，正是和这个有关。我们可以把使用 ref 看做是风格一，使用 reactive 对应风格二：

	// 风格一
	const x = ref(0)
	const y = ref(0)
	const isDisplay = ref(false)

	// 风格二
	const state = reactive({
	  x: 0,
	  y: 0,
	  isDisplay: false
	})


## Vue 3.0 render

在 Vue 3.0 中依然保留了 render 这个功能，而且还为符合 Composition API 的编程理念做了调整。

让我们来用 render 方法改写一下之前的计数器代码，看起来就会是这样的：

	const { createApp, ref, h } = Vue

	// 计数器组件
	const Counter = {
	    setup() {
	        const countOps = useCount()
	        return { ...countOps }
	    },

	    render() {
	        return [
	            h('div', { class: 'counter-display' }, [
	                h('span', { class: 'counter-label' }, '恭喜你，你已经写了'),
	                h('span', { class: 'counter-text' }, this.count),
	                h('span', { class: 'counter-label' }, '斤代码！'),
	            ]),
	            h('div', { class: 'counter-btns' }, [
	                h('button', { class: 'btn', onClick: this.increase }, '写一斤'),
	                h('button', { class: 'btn', onClick: this.reset }, '删库啦'),
	            ])
	        ]
	    }
	}

	function useCount() {
	    const count = ref(0)
	    const increase = () => { count.value++ }
	    const reset = () => { count.value = 0 }
	    return { count, increase, reset }
	}

	// 根组件
	const App = {
	    render() {
	        return h('div', { class: 'container' }, [
	            h('h3', '计数器示例'),
	            h(Counter)
	        ])
	    }
	}

	// 启动
	const container = document.querySelector('#app')
	const app = createApp()

	app.mount(App, container)

我们可以看到变化的地方：原先的 template 不见了，取而代之的是一个 render 方法，方法中通过 h 函数创建虚拟DOM节点（这个h 函数和Vue2.0中 render 方法的参数 createElement 是类似的）。如果我们使用了 JSX，那 render 方法中更可以使用 JSX 的语法来编写虚拟DOM的创建，看起来会是这样：

	const App = {
	    render() {
	        return (
	          <div className="container">
	            <h3>计数器示例</h3>
	            <Counter />
	          </div>
	        )
	    }
	}

然而，有心的朋友可能会从上面这些代码中观察到一个问题，我们还是在 render 方法中使用到了 this 对象，当然这在实现功能上面并不存在什么问题，但是，这跟 Composition API 提倡的函数式做法的理念并不一致。

其实，新的框架已经考虑到了这一点，并给出了方案：在 setup 方法中返回这个 render 方法。我们的 Counter 组件如果按照上面的方案改写一下，就会是这样：

	const Counter = {
	    setup() {
	        const { count, increase, reset } = useCount()

	        return () => [
	            h('div', { class: 'counter-display' }, [
	                h('span', { class: 'counter-label' }, '恭喜你，你已经写了'),
	                h('span', { class: 'counter-text' }, count.value),
	                h('span', { class: 'counter-label' }, '斤代码！'),
	            ]),
	            h('div', { class: 'counter-btns' }, [
	                h('button', { class: 'btn', onClick: increase }, '写一斤'),
	                h('button', { class: 'btn', onClick: reset }, '删库啦'),
	            ])
	        ]
	    }
	}

如此一来，我们就完全摆脱对 this 的使用啦。


## Vue 3.0 Props

组件，是封装和复用性的体现。封装，将尽量少的细节暴露给外界；复用，在保证整体功能的情况下通过一些方式提供灵活性、可变性。这些设计指导原则可以让我们在程序开发的过程中，写出组织良好，可维护性比较高的代码。

组件的属性就是这样一种方式，可以让组件和外部（其他组件）之间进行有限的沟通，同时也让组件拥有了可配置性。使用过Vue2.x的朋友一定对组件的属性非常熟悉，其实Vue3.0的属性用法和Vue2.x的差不多。

仍以之前的计数器例子为基础，为它添加一些属性相关的功能：我们希望在创建计数器的时候，可以设置它初始计数值，然后后续的点击计数基于这个初始值进行累加，而不是从0开始累加。

来看下我的代码是怎么做的，是不是和你猜想中的差不多：

第一步：我们首先是为 Counter 组件使用如下代码定义了一个名为 initCount 的属性，类型为数字，默认值为 0：

	props: {
	    initCount: {
	        type: Number,
	        default: 0
	    }
	}

第二部：我们改造了一下 useCount 函数，让它接收一个初始值参数来初始化响应式数据 count，而不是直接用 0：

	function useCount(initCount) {
	    const count = ref(initCount)
	    //...
	}

第三部：通过 setup 方法的第一个参数，我们可以获取到传入组件的属性值，并调用改造过的 useCount 函数：

	setup(props) {
	    const { count, increase, reset } = useCount(props.initCount)
	    // ...
	}

第四部：经过上面的改造，Counter组件改造完成。最后就是在使用这个组件的时候传入我们想要的初始值：

	// 使用render函数渲染
	h(Counter, { initCount: 99 })

	<!-- 使用模板渲染 -->
	<Counter initCount="99" />

改造完成，运行程序后，我们看到的界面数字就是这个设定的初始值啦！


希望通过以上这个简单的例子，大家初步掌握了属性的基本用法。下面是完整的代码，供大家参考：

	const { createApp, ref, h } = Vue

	// 计数器组件
	const Counter = {

	    // 属性定义
	    props: {
	        initCount: {
	            type: Number,
	            default: 0
	        }
	    },
	    
	    // setup的第一个参数为传入的属性值
	    setup(props) {
	        const { count, increase, reset } = useCount(props.initCount)

	        return () => [
	            h('div', { class: 'counter-display' }, [
	                h('span', { class: 'counter-label' }, '恭喜你，你已经写了'),
	                h('span', { class: 'counter-text' }, count.value),
	                h('span', { class: 'counter-label' }, '斤代码！'),
	            ]),
	            h('div', { class: 'counter-btns' }, [
	                h('button', { class: 'btn', onClick: increase }, '写一斤'),
	                h('button', { class: 'btn', onClick: reset }, '删库啦'),
	            ])
	        ]
	    }
	}

	// 使用初始计数值
	function useCount(initCount) {
	    const count = ref(initCount)
	    const increase = () => { count.value++ }
	    const reset = () => { count.value = 0 }
	    return { count, increase, reset }
	}

	// 根组件
	const App = {
	    render() {
	        return h('div', { class: 'container' }, [
	            h('h3', '计数器示例'),
	            h(Counter, { initCount: 99 })  // 传入初始值 99
	        ])
	    }
	}

	// 启动
	const container = document.querySelector('#app')
	const app = createApp()

	app.mount(App, container)


# Vue 3.0 Life-Cycle

在组件化的框架中，比如Angular、React或Vue，都为组件定义了生命周期这个概念，每个组件实例在被创建时都要经过一系列的初始化过程，例如：需要设置数据监听、编译模板、将实例挂载到 DOM 并在数据变化时更新 DOM 等。同时，在这个过程中也会运行一些叫做生命周期钩子的函数，它们提供给用户在组件的不同阶段添加自己的代码的机会。

使用过 Vue 2.x 的朋友肯定对它的生命周期钩子很熟悉了，因为在实际的开发过程中我们多多少少会用到他们，比如 created、mounted、destoryed 等等。而在 Vue 3.0 中，Vue 2.x Options API 形式的生命周期钩子函数和新的 Composition API 都可以使用，来看个示例代码就明白了：

	const { onMounted } = Vue

	const MyComp = {
	    
	    // Options API
	    mounted() {
	        console.log('>>>>>> mounted 1')
	    },
	    
	    setup() {
	        // Composition API
	        onMounted(() => {
	            console.log('++++++ mounted 2')
	        })
	    }
	}

两种形式的生命周期函数可以共存（当然实际使用的时候最好只选用一种），它们都会被执行。Composition API 形式的生命周期函数都是在 setup 方法中被调用注册。

最后，在实际的开发过程中，请注意一下 Options API 形式的组件生命周期钩子和 Composition API 之间的实际对应关系：

	beforeCreate  -> 请使用 setup()
	created       -> 请使用 setup()
	beforeMount   -> onBeforeMount
	mounted       -> onMounted
	beforeUpdate  -> onBeforeUpdate
	updated       -> onUpdated
	beforeDestroy -> onBeforeUnmount
	destroyed     -> onUnmounted
	errorCaptured -> onErrorCaptured


## Vue 3.0 more reactive

Vue 3.0 的一些新特性，尤其是新的 Composition API 的用法。这套新的API中最重要、最核心的部分，恐怕就是实现响应式功能的这一块了。而且，这套响应式 API 不仅可以在 Vue 3.0 环境下使用，也可以独立使用。

响应式API主要由2大类组成：

- 针对原始的数据，将其包装成可观察数据的API （ref、reactive）
- 针对可观察数据的变动，执行监听和响应动作的API （effect、computed）

包装API和监听API这2者之间互相协同工作，组成一个完整的响应式系统。下面我们来通过一些简单的例子，观察和了解一下它们是如何进行协同工作的。

示例一：ref + effect
在前面的文章中我们提到过，ref 函数可以将一个数据包装成一个响应式数据对象（Ref类型），该函数的TypeScript类型定义如下：

	function ref<T>(raw: T): Ref<T>

effect 函数则可以接受一个监听函数，如果这个监听函数中存在对响应式数据对象的访问，则一旦这些响应式数据对象的值发生变化，该监听函数就会被执行。

来看一个简单的代码示例：

	const { ref, effect } = Vue

	// 创建观察对象
	const greeting = ref("Hello,World!")

	// 监听数据变化
	effect(() => {
	    console.log(greeting.value)
	})

	// 再让数据改变一下吧
	greeting.value = "Are you OK?"

以上这段代码先使用 ref 函数创建了一个名为 greeting 的可观察对象，然后通过 effect 函数创建对 greeting 值变化的监听器，对值进行打印。这段代码的执行结果是打印出：

	Hello,World!
	Are you OK?

这个还是很好理解的，因为这个 greeting 包含的值一共变化了2次，第一次是初始化时设置的 “Hello,World!”，第二次是后面设置的 "Are you OK?"。

示例二：ref 作用于数组数据
在Vue2.x中，对一个数组中的每个元素进行响应式变化监听，做起来还是稍微有点麻烦和不优雅的。在Vue3.0中，这个问题被很好的解决了。

	const { ref, effect } = Vue

	// 创建一个对数组的观察对象
	const arr = ref([1, 2, 3])

	effect(() => {
	    console.log(arr.value[0])
	})

	// 改变整个数组
	arr.value = [5, 6, 7]

	// 改变数组中的第一个元素
	arr.value[0] = 111

上面这段代码示例输出的结果是：

	1
	5
	111

由此可以说明，在这段代码中，无论是对整个数组重新赋值，还是对数组中的某个元素赋值，都可以被精准的监听到。

示例三：ref 的嵌套
由 ref 函数创建的可观察对象可以嵌套使用。

	const { ref, effect } = Vue

	const a = ref(1)
	const b = ref(2)
	const c = ref({ x: a, y: b })

	effect(() => {
	    console.log(c.value.x + c.value.y)
	})

	// 从c对象上去间接改变a和b值
	c.value.x = 5
	c.value.y = 10

	// 直接改变a和b的值
	a.value = 20
	b.value = 60

可以看到，可观察对象 c 中包含了对其他2个可观察对象 a 和 b的引用。这段代码的最终执行结果为如下：

	3
	7
	15
	30
	80

由此可见，无论是通过嵌套引用来改变可观察对象值，或是直接改变可观察对象值，effect 创建的监听器都能正确响应这些变化。

示例四：reactive + effect
之前的文章中也提到过，除了 ref 函数，reactive 是Composition API中的另一个可用于创建可观察对象的函数。最简单的用法如下：

	const { reactive, effect } = Vue

	const state = reactive({ a: 1, b: 'Hello' })

	effect(() => {
	    console.log(state.a)
	})

	state.a = 2

使用 reactive 的好处是一次性可以观察多个属性。不过，自从ES6+流行后，我们在实际的代码编写过程中，是不是经常会用到对象解构操作？比如像这样：

	const obj = { a: 1, b: 2 }
	const { a, b } = obj

而在对可观察对象进行操作的时候，你一定也会自然而然的想这么干：

	const state = reactive({ a: 1, b })
	let { a, b } = state

	state.a = 123 //可以
	a = 123 // 行不通！变成不可观察了

为什么将可观察对象中的属性解构出来后，变成不再可观察了呢？因为通过 reactive 函数创建的可观察对象，内部的属性本身并不是可观察类型的，对他们访问和观察其实都是通过Proxy代理访问来实现的。如果将这些属性解构，这些属性就不再通过原对象的代理来访问了，就无法再进行观察。

不过，Composition API也考虑到了这一点，提供了方法来解决这一个问题：

	const { reactive, effect, toRefs } = Vue

	const state = reactive({ a: 1, b: 2 })

	// 这里的a和b都是Ref类型对象
	const { a, b } = toRefs(state)

	effect(() => {
	    console.log(a.value)
	})

	a.value = 123

通过引入一个 toRefs 函数，它可以将 reactive 创建的可观察对象中的属性都转换成可观察的 Ref 对象，这样一来，即使解构后，也可以被独立进行观察了。

示例五：computed
用过Vue的朋友，一定对计算属性不陌生，一般用于定义一个虚拟属性，这个虚拟属性的值来源于一个或多个可观察对象的变化而产生。在Composition API中也有对应的功能：

	const { computed, ref } = Vue

	// 可观察对象
	const num = ref(1)

	// 计算属性
	const text = computed(() => {
	    return `Value is ${num.value}`
	})

	console.log(text.value)

	// 改动可观察对象的值
	num.value = 2

	console.log(text.value)

这个例子中，我们根据数字类型的 num，来生成新的字符串 text，实现了一个比较方便的数据生成转换。

总结
Vue 3.0的Composition API提供了上文示例中所展示的这些简单而有效的函数，实现了响应式功能。其实它们还提供了一些可选项参数，用于实现更为丰富的功能，大家可以自己阅读源码深入研究一下，非常有意思，同时也可以从优秀的源码中学习和提高自己的编程水平。



# Life-Cycle 与组件销毁重建

了解决 Vue 组件生命周期是理解 Vue 工作原理的基础，更新版本后 Vue 2.0 的生命周期函数的设计更合理了，以下是 Vue 2.0 和 1.0 的生命周期函数对比

|vue 1.0		|vue 2.0		|说明	|
|---------------|---------------|-------|
|init			|`beforeCreate`	|创建前，data和el都还未初始化|
|create			|`create`		|完成创建，data数据已初始化但el没有|
|beforeCompile	|`beforeMount`	|载入前，完成了data和el数据初始化，模板内容还未替换|
|compile/ready	|`mounted`		|载入后，载入后html已经渲染，ajax请求可以放在这个函数中|
|----			|`beforeUpdate`	|更新前，view层的数据变化前，不是data中的数据改变前|
|----			|`update`		|更新后|
|----			|`activated`	|keep-alive 组件激活时调用|
|----			|`deactivated`	|keep-alive 组件停用时调用|
|attached		|----			|	|
|detached		|----			|	|
|beforeDestroy	|`beforeDestroy`|销毁前|
|destroyed		|`destroyed`	|销毁后，Dom元素存在但不受Vue控制|
|----			|`errorCaptured`|错误捕捉|


`$destory()` 函数可以触发组件销毁动作，清理过程只是在移除它和其它实例的连接，解除指令以及事件监听器，还有断掉虚拟dom和真实dom之间的联系。HTML 节点并没真正地没有回收，而且 `$on` 绑定的函数在 `$destory()` 过程也没有销毁掉，所以 HTML 还可以进行交互操作。

利用组件的挂载节点属性 `$el` 来清理组件的 HTML 元素，`vm.$el.remove()`，或者使用 Vue 1.0 提供的 `vm.$destroy( [remove] )` 方法，参数 `remove` 设置 true 直接解除 HTML 元素，此方法在 Vue 2.0 中已经弃了。参考[升迁 Vue 1.x](https://vuejs.org/v2/guide/migration.html#vm-remove-removed)。

要销毁一类组件可以将组件名传入销毁方法，例如销毁所有 MessageBox 组件 `this.$destroy("MessageBox")`，这种销毁方法只对 this 指向的父组件下的子组件有效。

通过 `$once` 绑定生命同期事件：

	mounted: function () {
	  this.$once('hook:beforeDestroy', function () {
	    // vm.$destroy()
	  })
	}

在 `beforeDestroy` 事件中可以进行清理工作，如果通过 `vm.$el.remove()` 移除挂载节点，那么后续的组件在实例化时将不会再渲染得到视图。要保持后续实例化的组件拥有相同的视图，那么在销毁组件过程中就不能移除挂载节点，而是将节点隐藏，一个做法就是通过样式属性 `display` 来实现：

	this.$el.style.display = "none";

Vue 会自行处理这些 HMTL 节点，并且会对它们回收再利用。

PS: 使用 VueRouter 路由插件时，在路由切换的过程中，并不会触发组件的销毁过程，但视图渲染函数是会重新执行的。为了避免组件渲染受到 Vue 内部就地复用旧视图的影响，可以使用唯一的 `key` 属性值来保证视图被重新渲染。

在处理组件的销毁过程中可能需要到状态过度动画，可以使用 CSS 3 的 animation，也可以使用 `transition` 组件，参考 [进入/离开 & 列表过渡]，这里有许多富有创意的动画效果。

[进入/离开 & 列表过渡]: https://cn.vuejs.org/v2/guide/transitions.html

了解 Vue 的生命周期后，还有必要了解决以下这组 Vue 实例属性：

|实例属性	|说明	|
|-----------|-------|
|[`vm.$data`][vm.$data]	|Vue 实例观察的数据对象，Vue 代理了对实例化参数中 data 对象属性的访问。	|
|[`vm.$props`][vm.$props]	|当前组件接收到的 props 对象。Vue 实例代理了对其 props 对象属性的访问。	|
|[`vm.$el`][vm.$el]	|Vue 实例使用的根 DOM 元素。	|
|[`vm.$options`][vm.$options]	|访问当前 Vue 实例的初始化传入的参数。	|
|[`vm.$parent`][vm.$parent]	|父实例引用，如果当前实例是顶级则返回 `undefined`。	|
|[`vm.$root`][vm.$root]	|当前组件树的根 Vue 实例。如果当前实例没有父实例，此实例将会是其自己。	|
|[`vm.$children`][vm.$children]	|当前实例的直接子组件。需要注意 `$children` 并不保证顺序，也不是响应式的。	|
|[`vm.$slots`][vm.$slots]	|访问被插槽分发的内容。具名插槽有其相应的属性名。默认的插槽的内容对应 `default` 属性，即通过 `v-slot:default` 绑定的内容，可以结合渲染函数编写组件。	|
|[`vm.$scopedSlots`][vm.$scopedSlots]	|用来访问作用域插槽。对于包括 默认 slot 在内的每一个插槽，该对象都包含一个返回相应 VNode 的函数。所有 $slots 都会作为函数暴露在 `$scopedSlots` 中。	|
|[`vm.$refs`][vm.$refs]	|返回通过 `ref` 特性注册的所有 DOM 元素和组件实例。	|
|[`vm.$isServer`][vm.$isServer]	|当前 Vue 实例是否运行于服务器，即服务端渲染的组件。	|
|[`vm.$attrs`][vm.$attrs]	|在组件内部用来访问父作用域传入的非 `props` 参数，`class` 和 `style` 除外。并且父组件可以通过 `v-bind="$attrs"` 方式传入，在创建高级别的组件时非常有用。	|
|[`vm.$listeners`][vm.$listeners]	|在组件内部用来访问父作用域中的 `v-on` 事件监听器，`.native` 修饰器的除外。它可以通过 `v-on="$listeners"` 传入内部组件——在创建更高层次的组件时非常有用。	|


Vue 的核心内容有三大块，一是响应式的实现，二提模板编译实现，三是 Virtual DOM 机制实现。

模板编译 compile 可以分成三个阶段，最终得到的结果是一个渲染函数 `render`。解析阶段 parse 会用正则等方式解析模板中的指令、class、style等数据，形成抽象语法树 AST。优化阶段 optimize 的主要作用是标记 static 静态节点，在后面 update 更新视图时，有相应的 patch 过程，通过 diff 算法可以跳过静态节点，优化性能。生成阶段 generate 是将 AST 转化成渲染函数的过程，得到的结果是 render 函数的字符串以及 staticRenderFns 字符串。经过模板编译后，组件中就会存在产生 VNode 节点所需的渲染函数了。

Vue 内部使用 Virtual DOM 来管理视图树，就是以 JavaScript 对象 VNode 节点作为基础的树。通过对象属性来描述节点，在内存中抽象表达了真实 DOM 结构，但比浏览器的 DOM 操作更节能。另一方面，Virtual DOM 以 JavaScript 对象为基础不依赖真实平台环境，使得它天生具有跨平台的能力，全球最大的电商阿里就将它的跨平台能力应用到了 Weex 这个项目。

Vue 的数据响应机制检测到数据变化后，就会执行渲染函数，每个渲染函数 `render` 都会转化成 VNode 节点。 想要得到视图，最简单粗暴的方法就是直接解析这个新的 VNode 节点，然后通过浏览器提供的节点属性 `innerHTML` 生成。

Vue 内部当然不会这样做，对那些只修改了其中的一小块内容内容的节点，会经过特殊的 `patch` 方法处理，将新旧的 VNode 进行比较，经过 diff 算法得到差异结果，最后只需要将这些有差异的节点更新到浏览器对应 DOM 节点上，这个过程就涉及了 Vue 的就地利用机制，使用唯一的 `key` 可以保证组件的正确的渲染，而不受复用机制影响。



# 组件开发 c-radio
https://cn.vuejs.org/v2/guide/components.html
https://www.jianshu.com/p/a47d91d0ef12

	<!DOCTYPE html>
	<html>
	<head>
		<meta charset="utf-8">
		<title>component example</title>
		<meta name="viewport" content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
		<script src="https://apps.bdimg.com/libs/zepto/1.1.4/zepto.min.js"></script>
		<script type="text/javascript" src="http://vuejs.org/js/vue.min.js"></script>
		<link rel="stylesheet" type="text/css" href="http://unpkg.com/iview/dist/styles/iview.css">
		<script type="text/javascript" src="http://unpkg.com/iview/dist/iview.min.js"></script>
	</head>
	<body>
	<style>
		.radio-frame {}
		.radio-frame .title { }
		.radio-frame .icon { float:right; width:20px;height:20px;background:#cccccc; position:relative;border-radius:20px; }
		.radio-frame .icon::after { content:"";width:18px;height:18px;position:absolute;left:1px;top:1px;background:#ffffff;border-radius:20px; }
		.radio-frame .item-active .icon::after{ animation: loading 0.2s steps(9, start); width:8px;height:8px;left:6px;top:6px;}
		.radio-frame .item-active .icon { background:#26a2ff; }
		.radio-frame .item {padding:8px 8px;font-size:1.3em;margin-top:-1px;border:1px solid #d9d9d9;border-left: none;border-right:none;}
		@keyframes loading {
			50% { width:12px;height:12px;left:4px;top:4px; }
			100% { width:8px;height:8px;left:6px;top:6px; }
		}
	</style>
	<div id="app">
		<i-button @click="show">Click me!</i-button>
		<Modal v-model="visible" title="Message">pick {{price}}</Modal>
		<button class="ivu-btn ivu-btn-primary ivu-btn-large" type="primary" @click.native="go2pay">{{"请先登录"}}</button>

		<c-radio align="left" v-model="price" @update="show" :options="products" @click.native="setOptions"></c-radio>
	</div>
	<script>

	Vue.component('c-radio', {
		data: function () {
			return { count: 0 };
		},
		props: ['options'],
		methods:{
			setTarget: function (event) {
				let target = event.currentTarget;
				let value  = event.currentTarget.dataset.value;
				console.log("setTarget", this, target, value);
				this.target = target;
				this.$emit("input", value);
			},
			updateState: function (event) {
				let els=event.currentTarget.getElementsByClassName('item'); 
				for(var p of els) {
					p.className=p.className.replace('item-active','');
				}
				this.target.className+=' item-active';
				this.$emit("update", this.target.dataset.value);
				console.log("updateState", this, event, event.srcElement, event.target, event.toElement);//
			}
		},
		template:
		'<div class="radio-frame" @click="updateState">'+
		'   <div class="item" v-for="(item,index) in options" @click.capture="setTarget" :index="index" :data-value="item.value">'+
		'       <label class="icon"></label>'+
		'       <label class="title" v-html="item.label">{{count}}</label>'+
		'   </div>'+
		'</div>'
	})

	new Vue({
		el: '#app',
		data: {
			price:0,
			visible: false,
			products: [
				{label:"体验7天VIP: ￥20.00 (仅限新用户)", value:20.00},
				{label:"月度VIP: ￥99.00 <del>(原价320)</del>", value:99.00},
				{label:"季度VIP: ￥198.00 <del>(原价640)</del>", value:198.00},
				{label:"季度VIP: ￥396.00 <del>(原价1280)</del>", value:396.00},
			]
		},
		methods: {
			setOptions: function (event) {
				console.log("setOptions", this, event);
			},
			show: function (event) {
				console.log("show", event, this);
				this.visible = true;
				let that = this;
				setTimeout(function(){ that.visible=false; }, 600);
			}
		}
	})
	</script>
	</body>
	</html>


# Vue CLI 3 新特性

## CLI 服务
[CLI 服务](https://cli.vuejs.org/zh/guide/cli-service.html#使用命令)

在 Vue CLI 3 项目 `@vue/cli-service` 模块安装了一个名为 `vue-cli-service` 的命令。可以通过 `npm run serve` 执行 npm scripts 的配置、或者从终端中以 `./node_modules/.bin/vue-cli-service` 访问这个命令。

	{
	  "scripts": {
	    "serve": "vue-cli-service serve",
	    "build": "vue-cli-service build"
	  }
	}

最新版的 npm 应该已经自带 npx，也可以使用，调用命令参考：

	npm run serve
	yarn serve
	npx vue-cli-service serve

### vue-cli-service serve

命令用法：`vue-cli-service serve [options] [entry]`

	--open    在服务器启动时打开浏览器
	--copy    在服务器启动时将 URL 复制到剪切版
	--mode    指定环境模式 (默认值：development)
	--host    指定 host (默认值：0.0.0.0)
	--port    指定 port (默认值：8080)
	--https   使用 https (默认值：false)

vue-cli-service serve 命令会启动一个开发服务器 (基于 webpack-dev-server) 并附带开箱即用的模块热重载 (Hot-Module-Replacement)。

除了通过命令行参数，你也可以使用 vue.config.js 里的 devServer 字段配置开发服务器。

命令行参数 [entry] 将被指定为唯一入口，而非额外的追加入口。尝试使用 [entry] 覆盖 config.pages 中的 entry 将可能引发错误。

### vue-cli-service build
命令用法：`vue-cli-service build [options] [entry|pattern]`

选项：

	--mode        指定环境模式 (默认值：production)
	--dest        指定输出目录 (默认值：dist)
	--modern      面向现代浏览器带自动回退地构建应用
	--target      app | lib | wc | wc-async (默认值：app)
	--name        库或 Web Components 模式下的名字 (默认值：package.json 中的 "name" 字段或入口文件名)
	--no-clean    在构建项目之前不清除目标目录
	--report      生成 report.html 以帮助分析包内容
	--report-json 生成 report.json 以帮助分析包内容
	--watch       监听文件变化

`vue-cli-service build` 会在 dist/ 目录产生一个可用于生产环境的包，带有 JS/CSS/HTML 的压缩，和为更好的缓存而做的自动的 vendor chunk splitting。它的 chunk manifest 会内联在 HTML 里。

这里还有一些有用的命令参数：

	--modern 使用现代模式构建应用，为现代浏览器交付原生支持的 ES2015 代码，并生成一个兼容老浏览器的包用来自动回退。
	--target 允许你将项目中的任何组件以一个库或 Web Components 组件的方式进行构建。
	--report 和 --report-json 会根据构建统计生成报告，它会帮助你分析包中包含的模块们的大小。

### --target 指定构建目标

可以通过 `--target` 选项指定不同的构建目标，它允许你将相同的源代码根据不同的用例生成不同的[构建目标](https://cli.vuejs.org/zh/guide/build-targets.html#应用)，有 `应用模式`、 `库模式`、 `Web Components 组件模式`、 `异步 Web Components 模式` 四种。

**应用模式**是默认的，在这个模式中 `index.html` 会注入资源和 resource hint，第三方库会被分到一个独立包以便更好的缓存，小于 4kb 的静态资源会被内联在 JavaScript 中，`public` 目录中的公共静态资源会被复制到输出目录中。

**库模式**可以通过下面的命令将一个单独的入口构建为一个库：

	vue-cli-service build --target lib --name myLib [entry]

在库模式中，Vue 是外置的。这意味着包中不会有 Vue，即便你在代码中导入了 Vue。如果这个库会通过一个打包器使用，它将尝试通过打包器以依赖的方式加载 Vue；否则就会回退到一个全局的 Vue 变量。`[entry]` 指定的入口可以是一个 `.js` 或一个 `.vue` 文件。如果没有指定入口，则会使用 `src/App.vue`。

构建一个库会输出：

	dist/myLib.common.js   一个给打包器用的 CommonJS 包
	dist/myLib.umd.js      一个直接给浏览器或 AMD loader 使用的 UMD 包
	dist/myLib.umd.min.js  压缩后的 UMD 构建版本
	dist/myLib.css         提取出来的 CSS，可以在 vue.config.js 中设置 css: { extract: false } 强制内联

当使用一个 `.vue` 文件作为入口时，你的库会直接暴露这个 Vue 组件本身，因为组件始终是默认导出的内容。

使用一个 `.js` 或 `.ts` 文件作为入口时，它可能会包含具名导出，所以库会暴露为一个模块。也就是导出的库必须在 UMD 构建中或在 CommonJS 构建中通过导出模块的 `default` 访问。

	window.yourLib.default // UMD
	const myLib = require('mylib').default // CommonJS

如果你没有任何具名导出并希望直接暴露默认导出，你可以在 `vue.config.js` 中使用以下 webpack 配置：

	module.exports = {
	  configureWebpack: {
	    output: {
	      libraryExport: 'default'
	    }
	  }
	}

**Web Components 组件模式**可以通过一个单独的入口构建：

	vue-cli-service build --target wc --name my-element [entry]

在 Web Components 模式中，Vue 是外置的。这意味着包中不会有 Vue，即便你在代码中导入了 Vue。 这个模式允许你的组件的使用者以一个普通 DOM 元素的方式使用这个 Vue 组件，注意这个包依赖了在页面上全局可用的 Vue，即需要页面中有一个可用的全局变量 Vue。。

	<script src="https://unpkg.com/vue"></script>
	<script src="path/to/my-element.js"></script>

	<!-- 可在普通 HTML 中或者其它任何框架中使用 -->
	<my-element></my-element>

注意这里的入口应该是一个 `*.vue` 文件，Vue CLI 将会把这个组件自动包裹并注册为 Web Components 组件，无需在 `main.js` 里自行注册。

该构建将会产生一个单独的 JavaScript 文件并将所有的东西都内联起来。当这个脚本被引入网页时，会注册自定义组件 `<my-element>`，其使用 `@vue/web-component-wrapper` 包裹了目标的 Vue 组件。这个包裹器会自动代理属性、特性、事件和插槽。请查阅 `@vue/web-component-wrapper` 的文档了解更多细节。

可以使用一个 glob 表达式作为入口指定多个组件目标：

	vue-cli-service build --target wc --name foo 'src/components/*.vue'

当你构建多个 web component 时，`--name` 将会用于设置前缀，同时自定义元素的名称会由组件的文件名推导得出。比如一个名为 `HelloWorld.vue` 的组件携带 `--name foo` 将会生成的自定义元素名为 `<foo-hello-world>`。

**异步 Web Components 模式**当指定多个 Web Components 组件作为目标时，这个包可能会变得非常大，并且用户可能只想使用你的包中注册的一部分组件。通过指定 `--target wc-async` 会生成一个 `code-split` 的包，带一个只提供所有组件共享的运行时，并预先注册所有的自定义组件小入口文件。组件真正的实现只会在页面中用到自定义元素相应的一个实例时按需获取：

	vue-cli-service build --target wc-async --name foo 'src/components/*.vue'

打包得到的文件包含一个入口文件和各组件实现的独立文件：

	File                Size                        Gzipped
	dist/foo.0.min.js    12.80 kb                    8.09 kb
	dist/foo.min.js      7.45 kb                     3.17 kb
	dist/foo.1.min.js    2.91 kb                     1.02 kb
	dist/foo.js          22.51 kb                    6.67 kb
	dist/foo.0.js        17.27 kb                    8.83 kb
	dist/foo.1.js        5.24 kb                     1.64 kb

在页面上使用时只需要引入 Vue 和这个入口文件即可：

	<script src="https://unpkg.com/vue"></script>
	<script src="path/to/foo.min.js"></script>

	<!-- foo-one 的实现的 chunk 会在用到的时候自动获取 -->
	<foo-one></foo-one>


### vue-cli-service inspect

命令用法：`vue-cli-service inspect [options] [...paths]`

选项：

	--mode    指定环境模式 (默认值：development)

你可以使用 `vue-cli-service inspect` 来审查一个 Vue CLI 项目的 webpack config。更多细节请查阅审查 webpack config。


### 查看所有的可用命令

有些 CLI 插件会向 vue-cli-service 注入额外的命令。例如 @vue/cli-plugin-eslint 会注入 `vue-cli-service lint` 命令。以下命令查看所有注入的命令：

	npx vue-cli-service help
	npx vue-cli-service help [command]


## Fast-Prototype 快速原型开发

使用 `vue serve` 和 `vue build` 命令对单个 `*.vue` 文件进行快速原型开发，但需要先额外安装一个全局的扩展：

	npm install -g @vue/cli-service-global

vue serve 的缺点就是它需要安装全局依赖，这使得它在不同机器上的一致性不能得到保证。因此这只适用于快速原型开发。

### vue serve

	Usage: serve [options] [entry]

	[options]:
	-o, --open  打开浏览器
	-c, --copy  将本地 URL 复制到剪切板
	-h, --help  输出用法信息

在开发环境模式下零配置为 `.js` 或 `.vue` 文件启动一个服务器


`vue serve` 使用了和 `vue create` 创建的项目相同的默认设置 (webpack、Babel、PostCSS 和 ESLint)。它会在当前目录自动推导入口文件——入口可以是 `main.js`、`index.js`、`App.vue` 或 `app.vue` 中的一个，也可以显式地指定入口文件：

	vue serve MyComponent.vue

如果需要，你还可以提供一个 `index.html`、`package.json` 安装并使用本地依赖、甚至通过相应的配置文件配置 Babel、PostCSS 和 ESLint。


### vue build

	Usage: build [options] [entry]

	[options]:
	-t, --target <target>  构建目标 (app | lib | wc | wc-async, 默认值：app)
	-n, --name <name>      库的名字或 Web Components 组件的名字 (默认值：入口文件名)
	-d, --dest <dir>       输出目录 (默认值：dist)
	-h, --help             输出用法信息

在生产环境模式下零配置构建一个 `.js` 或 `.vue` 文件

你也可以使用 vue build 将目标文件构建成一个生产环境的包并用来部署：

	vue build MyComponent.vue

vue build 也提供了将组件构建成为一个库或一个 Web Components 组件的能力。


## vue create

`vue create` 命令创建一个由 `vue-cli-service` 提供支持的新项目，可以通过运行以下命令探索可选项：

	vue create --help

	create [options] <app-name>

	[options]:
	-p, --preset <presetName>       忽略提示符并使用已保存的或远程的预设选项
	-d, --default                   忽略提示符并使用默认预设选项
	-i, --inlinePreset <json>       忽略提示符并使用内联的 JSON 字符串预设选项
	-m, --packageManager <command>  在安装依赖时使用指定的 npm 客户端
	-r, --registry <url>            在安装依赖时使用指定的 npm registry
	-g, --git [message]             强制 / 跳过 git 初始化，并可选的指定初始化提交信息
	-n, --no-git                    跳过 git 初始化
	-f, --force                     覆写目标目录可能存在的配置
	-c, --clone                     使用 git clone 获取远程预设选项
	-x, --proxy                     使用指定的代理创建项目
	-b, --bare                      创建项目时省略默认组件中的新手指导信息
	-h, --help                      输出使用帮助信息

Vue CLI 3 开始支持项目管理图形界面 GUI，执行以下命令将开启 Web 服务提供的 Vue 项目管理器

	vue ui


Vue CLI 3 和旧版使用了相同的 vue 命令，所以 Vue CLI 2 即原来的 `vue-cli` 被新版命令覆盖了。如果需要使用旧版本的 `vue init` 功能，可以全局安装一个桥接工具，这样 `vue init` 的运行效果将会跟 `vue-cli@2.x` 相同：

	npm install -g @vue/cli-init
	vue init webpack my-project



# `vue.config.js` 配置参考

[Vue CLI 配置参考](https://cli.vuejs.org/zh/config/)
[HTML 和静态资源](https://cli.vuejs.org/zh/guide/html-and-static-assets.html#插值)
[Configuration Reference | Vue CLI][https://cli.vuejs.org/config/#eslint]
[Configuring ESLint - ESLint中文](http://eslint.cn/docs/user-guide/configuring)
[Vue CLI Deployment](https://cli.vuejs.org/guide/deployment.html)
[Vue CLI 部署](https://cli.vuejs.org/zh/guide/deployment.html)
[Vue CLI Environment Variables and Modes]: https://github.com/vuejs/vue-cli/blob/dev/docs/guide/mode-and-env.md

Vue-CLI 3.5 版本中子目录发布图片路径问题，可以找到模块目录下的选项文件，修改 `publicPath` 即可，开发使用的服务器端口及 IP 地址也可以在 `devServer` 中配置。`cli-service` 自带 `options.js` 配置文件，其中可以配置公共资源目录，可以解决子目录发布时图片路径问题。这个内置配置文件不建议直接修改，可以在工程根目录下设置一个 `vue.config.js` 配置文件。

	// node_modules\@vue\cli-service\lib\options.js
	publicPath: (process.env.NODE_ENV !== 'production'? "/":"/minis/vu/dist/"),

Vue 项目中有一个 public 文件夹，它用来存放那么不需要打包的资源文件，包括入口页面 index.html 等，这个文件夹下的所有资源会被直接拷贝到打包目录，即项目的 dist 目录下。

官方内置了一个CLI服务（@vue/cli-service），作为一个开发环境的依赖，局部安装在@vue/cli创建的项目中。如果你真想修改webpack的相关配置，可在项目的根目录下（和package.json同级）创建一个 `vue.config.js` 配置文件，@vue/cli-service会自动加载。也可直接使用package.json中的vue字段。

**publicPath** 部署应用包时的基本 URL。用法和 webpack 本身的 output.publicPath 一致，但是 Vue CLI 在一些其他地方也需要用到这个值，所以请始终使用 publicPath 而不要直接修改 webpack 的 output.publicPath。这个值也可以被设置为空字符串 ('') 或是相对路径 ('./')，这样所有的资源都会被链接为相对路径，这样打出来的包可以被部署在任意路径，也可以用在类似 Cordova hybrid 应用的文件系统中。从 Vue CLI 3.3 起已弃用 baseUrl，请使用publicPath。

**outputDir** 当运行 `vue-cli-service build` 时生成的生产环境构建文件的目录，默认值 `dist`。注意目标目录在构建之前会被清除，构建时传入 `--no-clean` 可避免清除旧文件。

**assetsDir** 放置生成的静态资源 (js、css、img、fonts) 的目录，相对于 `outputDir`。

**indexPath** 指定生成的 `index.html` 的输出路径，相对于 `outputDir`，也可以是一个绝对路径。

**lintOnSave** 是否在每次保存时 lint 代码，在开发环境下通过 `eslint-loader` 加载。这个值会在 `@vue/cli-plugin-eslint` 被安装之后生效。设置为 `true` 时，`eslint-loader` 会将 lint 错误输出为编译警告。默认情况下，警告仅仅会被输出到命令行，且不会使得编译失败。如果你希望让 lint 错误在开发时直接显示在浏览器中，可以设置为  `error`。这会强制 `eslint-loader` 将 lint 错误输出为编译错误，同时也意味着 lint 错误将会导致编译失败。

**runtimeCompiler** 设置为 true 支持运行时编译，这关就可以在 js 代码中使用模板字符串，Vue 会在运行时进行模板编译，这当然会降低运行效率并增加 js 文件大小。


在项目入口 `main.js` 中可以访问全局变量 `process` 得到配置信息，例如：

	process.env = {
		BASE_URL : "/minis/vu/dist/",
		NODE_ENV : "production"
	}

可以在入口中将这些配置信息注入到 Vue 中，以供其它组件使用：

	// 将环境变量注入
	Vue.prototype.processEnv = process.env;

BASE_URL - 对应 `vue.config.js` 中的 `publicPath`。
NODE_ENV - 对应 `development`、`production` 或 `test` 中的一个，具体的值取决于应用运行的模式。

注意，除了两个配置信息，其它以 `VUE_APP_` 开头的变量会被 `webpack.DefinePlugin` 静态嵌入到客户端侧的包中，在项目入口中这样访问它们：

	console.log(process.env.VUE_APP_SECRET)

在构建过程中，`process.env.VUE_APP_SECRET` 将会被相应的值所取代。

所有解析出来的环境变量都可以在 `public/index.html` 中以 HTML 插值中介绍的方式使用。因为 `index.html` 文件被用作模板，所以你可以使用 lodash template 语法插入内容：

	<%= VALUE %> 用来做不转义插值；
	<%- VALUE %> 用来做 HTML 转义插值；
	<% expression %> 用来描述 JavaScript 流程控制。

除了被 html-webpack-plugin 暴露的默认值之外，所有客户端环境变量也可以直接使用，例如 `BASE_URL`：

	<link rel="icon" href="<%= BASE_URL %>favicon.ico">

要定义环境变量，请在工程根目录下配置相应的文件，所有环境变量值按键值对书写 `VUE_APP_SECRET=***`，文件有四种，如下，带有 `local` 后缀的配置内容不会导出到发布的应用上，只能在本地开发时访问，参考文档 [Vue CLI Environment Variables and Modes]。

	.env                # loaded in all cases
	.env.local          # loaded in all cases, ignored by git
	.env.[mode]         # only loaded in specified mode
	.env.[mode].local   # only loaded in specified mode, ignored by git

	.env.local
	.env.development
	.env.production

在 CSS 或 `*.vue` 文件中使用相对路径，即路径以英文句点开头引用一个静态资源时，该资源将会被包含进入 webpack 的依赖图中。在其编译过程中，所有诸如 `<img src="...">`、`background: url(...)` 和 `CSS @import` 的资源 URL 都会被解析为一个模块依赖。在 Vue 内部通过 `file-loader` 用版本哈希值和正确的公共基础路径来决定最终的文件路径，再用 `url-loader` 将小于 4kb 的资源内联打包，以减少 HTTP 请求的数量。使用 JavaScript 代码引入资源的方法有以下两种方式：

	var img1 = require('../static/logo.png');
	import img2 from '../static/logo.png';


配置文件内容参考：

	module.exports = {
	  pages: {
	    index: {
	      // page 的入口
	      entry: 'src/main.js',
	      // 模板来源
	      template: 'public/index.html',
	      // 在 dist/index.html 的输出
	      filename: 'index.html',
	      // 当使用 title 选项时，
	      // template 中的 title 标签需要是 <title><%= htmlWebpackPlugin.options.title %></title>
	      title: 'Index Page',
	      // 在这个页面中包含的块，默认情况下会包含
	      // 提取出来的通用 chunk 和 vendor chunk。
	      chunks: ['chunk-vendors', 'chunk-common', 'index']
	    },
	    // 当使用只有入口的字符串格式时，
	    // 模板会被推导为 `public/subpage.html`
	    // 并且如果找不到的话，就回退到 `public/index.html`。
	    // 输出文件名会被推导为 `subpage.html`。
	    // subpage: 'src/subpage/main.js',
	  },

	  // whether to use eslint-loader
	  lintOnSave: process.env.NODE_ENV == 'not_production',
	  runtimeCompiler: true,
	  publicPath: (process.env.NODE_ENV !== 'production'? "base/":"/minis/vu/dist/"),

      // Webpack 配置会被 webpack-merge 合并入最终的 webpack 配置。
      // https://cli.vuejs.org/zh/guide/webpack.html
      configureWebpack: config => {
        plugins: [
          new MyAwesomeWebpackPlugin()
        ]
      },

	  devServer: {
	    host: '0.0.0.0',
	    port: 80,
	    overlay: {
          warnings: true,
          errors: true
        }
	    /*
	    open: process.platform === 'darwin',
	    host: '0.0.0.0',
	    port: 8080,
	    https: false,
	    hotOnly: false,
	    proxy: null, // string | Object
	    before: app => {}
	    */
	  }
	}


# EventBus or EventHub

组件间通信是一个基本功能需求，Vue 中组件间数据的传递大体有以下种方式：

+ 路由传值，在 Vue Router 路由中通过附加参数传值
+ 父子组件 `props` 属性传值
+ Vuex 状态管理仓库 store
+ EventBus 编程模式

在 Vue 2.0 中废弃了旧版的事件传递方式 `$dispath` 和 `$broadcast`。

`$dispath` 是由子组件发起事件通知，向其父组件链中寻找对应的事件监听。直到找到最近的父组件的一个事件监听之后停止寻找，除非监听器返回 `true`，如果该子组件存在对该事件的监听也会被触发。

`$broadcast` 则是由父组件向其子组件中传递消息，在子组件链路中找到事件监听之后，停止寻找，除非监听器返回 `true`。

因为基于组件树结构的事件流方式实在是让人难以理解，并且在组件结构扩展的过程中会变得越来越脆弱。并且$dispatch 和 $broadcast 也没有解决兄弟组件间的通信问题。

这些方法的最常见用途之一是父子组件的相互通信，使用 `v-on` 监听子组件上 `$emit` 触发的事件。然而，如果是跨多层父子组件通信的话，在组件上的 `$emit` 并没有什么用。而通过集中式的事件中间件则更灵活，这会让组件之间的通信非常顺利，即使是兄弟组件。

通过使用事件中心 EventBus，允许组件自由交流，无论组件处于组件树的哪一层。注意 EventBus 模式使用的 API 还是 `v-on`、 `$emit` 和 `$off`，只是触发这些 API 的上下文对应不是组件，而是顶级 Vue 实例，即在组件使用以下代码来触发、处理事件，只要保证触发事件和接收事件处理的上下文对象是同一个 Vue 实例就可以完成组件间的通信：

	this.$root.$on('demoEvent', (event)=>{ 
		console.log(event);
	});

	this.$root.$emit('demoEvent', {type:'myevent'});
	this.$root.$off('demoEvent');

通过 `$off` 来解除事件处理函数是一个好习惯。上面的代码就是 EventBus 的基本结构，但这种代码编写显得混乱了，特别是在大型项目中，这样的代码就会陷入一种无组织无管理的状态。因此，使用一个 EventBus 专用对象来组织这些代码显然是更好的选择。Vue 实例实现了一个事件分发接口，可以通过实例化一个空的 Vue 实例来实现这个目的。以下示例代码提供一个完整的范本：

一、在入口 `main.js` 中通过原型扩展给 Vue 初始化一个 `eventHub` 对象作为中央事件总线

	import Vue from 'vue'
	Vue.prototype.eventHub = new Vue();

二、在 `Hello.vue` 组件中使用扩展的 Vue 的实例属性 `eventHub` 来触发事件和处理事件

	<template>
	    <div class="hello">
	        <h3>{{name}} 组件</h3>
	        <button @click="send">广播事件</button>
	    </div>
	</template>

	<script>
	export default {
	    data(){
	        return {
	            name: 'Hello'
	        }
	    },
	    methods:{
	        send(){
	            this.eventHub.$emit('helloEvent',this.name)
	        }
	    }
	}
	</script>

三、在 `World.vue` 组件中订阅 `helloEvent` 事件，并在组件销毁时通过 `$off` 解除事件订阅

	<template>
	    <div class="world">
	        <h3>{{name}} 组件</h3>
	    </div>
	</template>

	<script>
	export default {
	    data(){
	        return {
	            name: 'World'
	        }
	    },
	    mounted(){
	        this.eventHub.$on('helloEvent',name => {
	            this.name = name
	        })
	    },
	    destroy(){
	        this.eventHub.$off('helloEvent'})
	    }
	}
	</script>


可以将 EventBus 做成一个独立模块，这样在需要使用的组件中就需要手动加载它，如官方提供的 Todos 示例，其应用结构如下：

	Todos
	├─ NewTodoInput
	└─ Todo
	   └─ DeleteTodoButton 触发事件的按钮组件

定义单独的事件中心来管理组件间的通信，`eventHub` 将在各处使用该事件中心，组件通过它来通信，这样组织的代码逻辑更清晰：

	var eventHub = new Vue()

然后在组件中，使用 `$emit`, `$on`, `$off` 分别来分发、监听、取消监听事件，最好在组件销毁前取消事件监听：

	// NewTodoInput ...
	methods: {
	  addTodo: function () {
	    eventHub.$emit('add-todo', { text: this.newTodoText })
	    this.newTodoText = ''
	  }
	}

	// DeleteTodoButton ...
	methods: {
	  deleteTodo: function (id) {
	    eventHub.$emit('delete-todo', id)
	  }
	}

	// Todos 主程序部分 ...
	created: function () {
	  eventHub.$on('add-todo', this.addTodo)
	  eventHub.$on('delete-todo', this.deleteTodo)
	},
	beforeDestroy: function () {
	  eventHub.$off('add-todo', this.addTodo)
	  eventHub.$off('delete-todo', this.deleteTodo)
	},
	methods: {
	  addTodo: function (newTodo) {
	    this.todos.push(newTodo)
	  },
	  deleteTodo: function (todoId) {
	    this.todos = this.todos.filter(function (todo) {
	      return todo.id !== todoId
	    })
	  }
	}



# SFC Single File Component 单文件组件概念
[Single File Components — Vue.js](https://vuejs.org/v2/guide/single-file-components.html)
[对比其他框架 — Vue.js](https://cn.vuejs.org/v2/guide/comparison.html)
[CSS 预处理器](https://cli.vuejs.org/zh/guide/css.html)

将脚本模板样式三合为一，以单个 vue 文件来编写组件，`script`、 `style` 可以通过 `src` 引入外部文件，也可以直接编写代码。

	<!-- my-component.vue -->
	<template>
	  <div>This will be pre-compiled</div>
	</template>
	<script src="./my-component.js"></script>
	<style src="./my-component.css"></style>


单文件组件让你可以在同一个文件里完全控制 CSS，将其作为组件代码的一部分，要使用 stylus 样式语法，可以添加 `lang="stylus"` 属性。

	<style scoped>
	  @media (min-width: 250px) {
	    .list-container:hover {
	      background: orange;
	    }
	  }
	</style>

这个可选 scoped 属性会自动添加一个唯一的属性 (比如 data-v-21e5b78) 为组件内 CSS 指定作用域，编译的时候 `.list-container:hover` 会被编译成类似 

	.list-container[data-v-21e5b78]:hover

Vue CLI 项目天生支持 PostCSS、CSS Modules 和包含 Sass、Less、Stylus 在内的预处理器，具体内容参考官方文档。

# 注册组件

引用组件时可以直接的需要使用组件的文件中，局部组件的注册，在当前文件中就可以使用该组件了，但是在其他组件中不能直接使用该组件。

	import Demo from './Demo.vue'

进行全局注册

	import Vue from 'vue'
	import Demo from './Demo.vue'
	Vue.component("Demo",Demo);

非 SFC 组件则直接定义组件并注册

	Vue.component('my-apprvuser',{
	  template:'',
	  data:function(){
	    return{}
	  }
	  //选项
	})

文件同级目录下的另一个 vue 文件中注册该组件的，需要在 `components` 中导出。

	import DemoUser from './DemoUser'

	export default {
	  components: {
	    'my-Demouser':DemoUser
	  },
	} 

可以在 Vue 实例化时通过 `components` 参数传入要进行局部注册的组件：

	new Vue({
	  components: {
	    // <my-component> 将只在父模板可用
	    'my-component': Child
	  }
	})

组件定义还可以通过 Mixin 的方式

	// 定义一个混合对象
	var myMixin = {
	  created: function () {
	    this.hello()
	  },
	  methods: {
	    hello: function () {
	      console.log('hello from mixin!')
	    }
	  }
	}
	var Component = Vue.extend({
	  mixins: [myMixin]
	})
	var component = new Component() // -> "hello from mixin!"

注意注册组件名字的设定，在 DOM 中使用一个组件 (而不是在字符串模板或单文件组件) 的时候，强烈推荐遵循 W3C 规范 中的自定义组件名 (字母全小写且必须包含一个连字符)。这会帮助你避免和当前以及未来的 HTML 元素相冲突。

定义组件名的方式有两种：

使用 kebab-case

	Vue.component('my-component-name', { /* ... */ })

当使用 kebab-case (短横线分隔命名) 定义一个组件时，你也必须在引用这个自定义元素时使用 kebab-case，例如 `<my-component-name>`。

使用 PascalCase

	Vue.component('MyComponentName', { /* ... */ })

当使用 PascalCase (驼峰式命名) 定义一个组件时，你在引用这个自定义元素时两种命名法都可以使用。也就是说 `<my-component-name>` 和 `<MyComponentName>`
	都是可接受的。注意，尽管如此，直接在 DOM (即非字符串的模板) 中使用时只有 kebab-case 是有效的。


# Ajax Vue-Resource & Axios v-for

Vue 2.0之后，作者就宣告不再对 Vue-Resource 更新，并且 Vue-Resource 不支持 SSR，所以推荐使用 Axios, 在服务端和客户端可以同时使用。注意 Vue-Resource 是 Vue 插件，而 Axios 不是，不能用 `Vue.use()` 的方式使用 Axios，但可以通过原型扩展的方式使用 Axios。

	<script src="https://cdn.bootcss.com/vue-resource/1.5.1/vue-resource.min.js"></script>
	<script type="text/javascript" src="http://vuejs.org/js/vue.min.js"></script>
	<link rel="stylesheet" type="text/css" href="http://unpkg.com/iview/dist/styles/iview.css">
	<script type="text/javascript" src="http://unpkg.com/iview/dist/iview.min.js"></script>

	<div id="app">
	    <i-button @click="show">Click me!</i-button>
	    <Modal v-model="visible" title="Welcome">Welcome {{message}} to iView</Modal>
		<div class="album">
			<img class="item" v-for="item in list" v-bind:src="'<?php echo CONF::UPLOADPATH ?>/'+item.thumb">
		</div>
	</div>
	<script>
	    new Vue({
	        el: '#app',
	        data: {
	        	list:[],
	        	message:"...",
	            visible: false
	        },
	        methods: {
	            show: function () {
	                this.visible = true;
	                var url = '/minis/index.php/album/index/0/20/1?ajax=true';
	                // this.$http.get(url).then(function(res){ var a = res.body or res.bodyText ...
	                // this.$http.jsonp(url,{'method':"POST"}).then(function(res){
	                this.$http.post(url,{arg:url},{emulateJSON:true}).then(function(res){
	                	console.log("ajax for json", res);
	                	this.list = res.body.data.list;
	                    this.message = res.body.msg;
	                },function(){
	                    console.log('请求失败处理');
	                });
	            }
	        }
	    })
	</script>


# Vue Plugin 与 Axios 非插件

Vue 插件机制是我见过最简单的了，只需要一个安装方法。插件使用 Vue.use() 进行全局引入，可以在其他组件中使用，通过插件对 Vue 的扩展可以实现 Vue 没有提供的功能，如 VueRouter 路由插件

	import VueRouter from 'vue-router'
	Vue.use(VueRouter)

非插件不能使用以上方式引用，像 Ajax 工具 Axios，可以通过原型扩展引入

	import Vue from 'vue'
	import axios from 'axios'

	Vue.prototype.axios = axios;
	
	new Vue({
	    el: '#app',
	    render:h => h(App),
	    created:()=>{ 
	    	this.axios.get('/url').then((res)=>{
	    		// load res.data from url
	    	}).catch();
	    }
	})

实现一个插件，只要给插件添加一个 install 方法，Vue 负责执行它将 Vue 作为参数传入，插件安装方法中的 `options` 参数就是 `Vue.use()` 传入的参数。通过扩展 Vue.propotype 原型链，可以实现需要的插件功能，如下实现一个多语言转换插件 `i18n.js`。

	let $lang = [];
	// $lang["language_key"] = "The actual message to be shown";

	$lang["Hello View Engine!"] = "你好 Vue Engine！";
	$lang["Welcome to Minis..."] = "欢迎来到 Minis！";
	$lang["No file deleted!"] = "注意文件没有删除！";

	export default {
	    install (Vue, options) {
	        // 1. add global method or property
	        Vue.lang = function (token) {
	            return token;
	        }

	        // 2. add a global asset
	        Vue.directive('my-directive', {
	            bind (el, binding, vnode, oldVnode) {
	            // some logic ...
	            }
	        })

	        // 3. inject some component options
	        Vue.mixin({
	            created: function () {
	                // console.log("i18N installed...");
	            }
	        })

	        // 4. add an instance method
	        Vue.prototype.lang = function (token) {
	            console.log("i18N.laning...", token, $lang[token]);
	            if ($lang[token]) return $lang[token];
	            return token;
	        }
	     
	        Vue.prototype.toast = function (token) {
	            console.log("i18N.toast...", token, $lang[token]);
	            if ($lang[token]) return alert($lang[token]);
	            return alert(token);
	        }

	    }
	}

在项目入口导入并安装插件后，就可以使用了，如 `this.lang('ABC')`

	import i18N from './i18N.js'
	Vue.use(i18N, {text:"myoption"});


# [Vue Router] 路由插件

[Vue Router]: https://router.vuejs.org/zh/
[Page.js]: https://github.com/visionmedia/page.js 
[Director]: https://github.com/flatiron/director
[History_API]: https://developer.mozilla.org/zh-CN/docs/Web/API/History_API
[解密vue-router: 从源码开始]: https://juejin.im/post/5af108dc518825672565cf31

[vue-router全解析一](https://blog.csdn.net/vv_bug/article/details/82795248)
[vue-router全解析二](https://blog.csdn.net/vv_bug/article/details/82766049)
[Vue2.0三——Vue-router](https://segmentfault.com/a/1190000012312441)


[Vue Router] 是 Vue.js 官方的路由管理器插件，它和 Vue.js 的核心深度集成，让构建单页面应用 SPA 变得易如反掌，包含的功能有：

0. 嵌套的路由/视图表
0. 模块化的、基于组件的路由配置
0. 路由参数、查询、通配符
0. 基于 Vue.js 过渡系统的视图过渡效果
0. 细粒度的导航控制
0. 带有自动激活的 CSS class 的链接
0. HTML5 历史模式或 hash 模式，在 IE9 中自动降级
0. 自定义的滚动条行为

也可以整合第三方路由，如 [Page.js] 或者 [Director]，当然，深入理解路由原理后，自己定制路由插件也是可以的，有时候自己造个轮子也不是什么坏事，无非就是花点时间。

在工程目录执行命令安装 vue-router 插件

	npm install vue-router

在工程入口中使用它，通过 Vue.use() 安装路由插件，然后将路由实例以 roter 参数传入 Vue 实例或组件，以下示例代码中路由配置 routes 为空，所以路由视图并不会得到匹配的内容：

	import Vue from 'vue'
	import VueRouter from 'vue-router'

	Vue.use(VueRouter)

	const router = new VueRouter({ routes:[] });

	new Vue({
		router:router,
		...
	});

引入路由后，可以通过内部变量 `this.$route` 来访问当前路由，或者通过 `this.$router` 引用路由器，可以在组件数据对象初始化函数或者 `beforeCreate` 这些生命周期事件上，注意这个事件会先于数据初始化函数执行。如 `/dashboard?a=b` 这个地址可以得到类似以下路由信息，其中 `path` 和 `fullPath` 的区别在与后者包含 `query` 即地址中问号后面的部分，具体根据路由配置有所不同：

	{
		fullPath: "/dashboard?a=b",
		hash: "",
		matched: [{
			beforeEnter: undefined,
			components: {default: {…}},
			instances: {default: VueComponent},
			matchAs: undefined,
			meta: {},
			name: undefined,
			parent: undefined,
			path: "/dashboard",
			props: {default: true},
			redirect: undefined,
			regex: /^\/dashboard(?:\/(?=$))?$/i
		}],
		meta: {},
		name: undefined,
		params: {},
		path: "/dashboard",
		query: {a: "b"}
	}

## Vue Router 实现原理


浏览器 `history` 对象提供了方法来处理历史记录，`pushState()` 用来向浏览器插入一条历史记录，`replaceState()` 方法用来替换浏览器中的一条历史记录。参考[History_API]，这两个方法可以在不重新加载页面的情况下修改location跟浏览器的历史记录。


如下，一个完整的页面地址由协议 `https`、主机名 `www.host.com:80`、页面地址 `/static/index.html`、查询字符串 `?query=123` 和 hash `#/user/110` 组成，注意 Web 默认端口 80 通常是省略不写的。

	https://www.host.com/static/index.html?query=123#/user/110

通过浏览器打印以下变量可知道

	location.href   "https://www.host.com/static/index.html?query=123#/user/110"
	location.search "?query=123"
	location.hash   "#/user/110"

通过给 `location.href` 一个新地址，页面就会刷新跳到指定的地址上，这相当点击一个超链接进入新页面。但是，如果新地址只有hash这部分不同，其它都一样的情况就不同了。地址整体是有变化的，但页面不会刷新跳转。通过脚本可以检测到这种变化，那将这种变化以一定的规则和需要呈现的视图绑定，这就是 Vue Router 干的事。通过监听 hashchange 事件（IE8已支持该事件），可以相应地址栏的变化，事件对象会有hash改变前的URL（oldURL）和hash改变后的URL（newURL）两个属性：

	window.addEventListener('hashchange',function(e) { console.log(e.oldURL);  console.log(e.newURL) },false);

Vue Router 工作流程中主要包含路由配置项、路由视图，配置项包含 `path` 属性用来配置地址栏的字符串，命中后就会将配置项 `component` 指定的组件渲染到路由视图上，页面显示相应的内容。匹配到路由配置后，路由链接标签 `router-link` 会增加 CSS 样式类 `.router-link-active`，并且当前被点击的标签还会添加 `.router-link-exact-active` 样式类，多个路由标签可能匹配到同一个路由配置。

例如，点击这样一个 Vue Router 路由链接:

    <router-link to="/user/110">Go to User</router-link>

浏览器地址栏就会改变hash部分：

	#/user/110

## Navigation Guards 导航守卫

Vue Router 提供强大的编程能力，通过 `go()`、 `push()`、 `replace()` 三个导航方法实现路由切换。也可以在路由执行切换过程中，使用**[导航守卫]**功能，通过各种守卫函数实现路由拦截处理。守卫是异步解析执行的，此时导航在所有守卫 resolve 完之前一直处于 等待中。这些守卫函数分成五种，**[全局前置守卫]** `beforeEach()`、 **[全局解析守卫]** `beforeResolve()`、 **[全局后置钩子]** `afterEach()`、 **[路由独享的守卫]**、 **[组件内的守卫]**。

每个守卫方法接收三个参数：

+ to: Route: 即将要进入的目标 路由对象
+ from: Route: 当前导航正要离开的路由
+ next: Function: 一定要调用该方法来 resolve 这个钩子。

给 `next()` 函数传入不同的参数效果各有不同：

`next()` 空参数表示直接进行管道中的下一个钩子即其它守卫函数。如果全部钩子执行完了，则导航的状态就是 confirmed 确认的，会进入视图渲染流程。

`next(false)` 中断当前的导航，检测到数据未保存可以使用。如果浏览器的 URL 改变了，那么 URL 地址会重置到 from 路由对应的地址，即使是手动改变了 URL。

`next('/')`、`next({ path: '/' })` 会导航到新的地址并中断当前触发的导航，有点像生定向的功能。可以向 next 传递任意位置对象，且允许设置诸如 `replace: true`、`name: 'home'` 之类的选项以及任何用在 `<router-link>` 的 `to` 属性或 `push()` 方法中的选项。

`next(error)` Vue 2.4.0+ 引入，如果传入参数是一个 `Error` 实例，则终止导航且错误会被传递给 `onError()` 注册过的回调。

当一个导航动作触发时，全局前置守卫按照创建顺序调用，注意，不同的组件都可以定义自己的路由器。在 Vue 2.5.0+ 可以使用全局解析守卫，它会在导航被确认之前，同时在所有组件内守卫和异步路由组件被解析之后被调用。注意全局后置钩子不会接受 next 函数也不能改变导航本身。

	const router = new VueRouter({ ... })

	router.beforeResolve((to, from, next) => { ... })
	router.beforeEach((to, from, next) => { ... })
	router.afterEach((to, from) => { ... })

路由独享的守卫在路由配置上直接定义 `beforeEnter`，这些守卫与全局前置守卫的方法参数是一样的。

	const router = new VueRouter({
		routes: [
			{ path: '/foo', component: Foo, beforeEnter: (to, from, next) => { ... } }
		]
	})

组件守卫，在 enter 守卫 `beforeRouteEnter()` 执行时组件实例还没被创建，因为对应路由被 confirm 前还未进入组件渲染程序，不能获取组件实例 `this`。可以通过传一个回调给 next 来访问组件实例。在导航被确认的时候会执行回调，并且把组件实例作为回调方法的参数，注意，这是唯一支持给 next 传递回调守卫函数。在当前路由改变，并且该组件被复用时会调用 `beforeRouteUpdate()`，举例来说，对于一个带有动态参数 `/foo/:id` 的路由配置，在 `/foo/1` 和 `/foo/2` 之间跳转，会渲染同样的 `Foo` 组件，因此组件实例会被复用，而这个钩子就会在这个情况下被调用，此时可以访问组件实例 `this`。导航离开该组件的对应路由时调用 leave 守卫 `beforeRouteLeave()`。

	const Foo = {
		template: `...`,
		beforeRouteEnter (to, from, next) { 
			// ...NO THIS...
			next(vm => {
				// CALLBACK for this
			})
		},
		beforeRouteUpdate (to, from, next) { ... },
		beforeRouteLeave (to, from, next) { ... }
	}


[导航守卫]: https://router.vuejs.org/zh/guide/advanced/navigation-guards.html
[全局前置守卫]: https://router.vuejs.org/zh/guide/advanced/navigation-guards.html#全局前置守卫
[全局解析守卫]: https://router.vuejs.org/zh/guide/advanced/navigation-guards.html#全局解析守卫
[全局后置钩子]: https://router.vuejs.org/zh/guide/advanced/navigation-guards.html#全局后置钩子
[路由独享的守卫]: https://router.vuejs.org/zh/guide/advanced/navigation-guards.html#路由独享的守卫
[组件内的守卫]: https://router.vuejs.org/zh/guide/advanced/navigation-guards.html#组件内的守卫

完整的导航解析流程：

+ 通过路由组件 `<router-link>` 触发导航。
+ 在失活的组件内的 `beforeRouteLeave()` 守卫函数被调用。
+ 全局前置守卫 `beforeEach()` 被调用。
+ 在重用的组件里调用 `beforeRouteUpdate()` 守卫 (Vue 2.2+)。
+ 在路由配置里调用 `beforeEnter()`。
+ 解析异步路由组件。
+ 在被激活的组件里调用 `beforeRouteEnter()`。
+ 调用全局解析守卫 `beforeResolve()` (Vue 2.5+)。
+ 导航被确认。
+ 调用全局的 `afterEach()` 钩子。
+ 触发 DOM 更新。
+ 用创建好的实例调用 `beforeRouteEnter()` 守卫中传给 `next()` 的回调函数。


## SPA单面应用

DEMO 展示要点

+ VueRouter 的基本使用方法
+ 路由视图，路由出口组件即生成路由结果的视图 `<router-view>`
+ 命名视图，给 `<router-view>` 组合设置 `name` 属性，默认值为 default
+ 使用命名视图，在路由配置中设置 `components` 而非 `component`
+ 命名路由，在路由配置项中使用了 `name` 属性
+ 嵌套路由，通过配置 `children` 给路由配置子级路由项目
+ 重定向路由配置项，`{ path: '/a', redirect: '/b' }` 将原本 `path` 匹配的路由地址重新路由到 `redirect` 属性指定的地址，可以使用命名路由或一个动态返回重定向目标的方法
+ 路由链接组件 `<router-link>` 会渲染成a标签，点击 `<router-link :to="...">` 等同于调用 `router.push("...")`。
+ 使用命名路由 `<router-link :to="{ name: 'user', params: { userId: 123 }}">User</router-link>`
+ 编程式的导航 

	router.go(n) 类似 window.history.go(n)。
	router.push(location, onComplete?, onAbort?)
	router.replace(location, onComplete?, onAbort?) 相当声明式 <router-link :to="..." replace>

	router.push('home') // 字符串
	router.push({ path: 'home' }) // 对象
	router.push({ name: 'user', params: { userId: 123 }}) // 命名的路由
	router.push({ path: 'register', query: { plan: 'private' }}) // 带查询参数，变成 /register?plan=private

参考[路由嵌套](https://router.vuejs.org/zh/guide/essentials/nested-routes.html)


	<script src="https://unpkg.com/vue/dist/vue.js"></script>
	<script src="https://unpkg.com/vue-router/dist/vue-router.js"></script>
	<style>
		.button { padding:2px; text-decoration: none; background:#00CAFF; border:1px solid #cccccc;}
		.button:hover {color:#fff;}
		.router-link-active {background:#FfBb00;}
	</style>

	<div id="app">
	  <h1>Hello App!</h1>
	  <p>
		<!-- 使用 router-link 组件来导航，它会被渲染成一个 `<a>` 标签，`to` 属性指定链接 -->
		<!-- IE天生天然残缺，不支持反引号，`/user/${id}/${name}`这样的模板字符串就不能使用了 -->
		<router-link class="button" to="/foo">Go to Foo</router-link>
		<router-link class="button" to="/bar">Go to Bar</router-link>
		<router-link class="button" :to="'/user/'+id+'/'+name">Go to User1 View</router-link>
		<router-link class="button" :to="'/user/112/Jimbo'">Go to User2 View</router-link>
		<button class="button" @click="goBack">Go Back</button>
		<span>Watching {{stamp}}</span>
	  </p>
	  <!-- 路由视图 路由出口 路由匹配到的组件将渲染在这里 -->
	  <router-view></router-view>
	  <!-- 命名视图 -->
	  <router-view name="secondary"></router-view>
	</div>

	<script>
		// 1. 定义组件。组件也可以通过 Vue.extend() 创建或者是一个组件配置对象
		const Foo  = { template: '<div>foo view</div>' }
		const Bar  = { template: '<div>bar view</div>' }
		const User = { 
			template:'<div>' + // 因为组件模板只能有一个顶级元素所以这里要使用div包裹两个子元素
					'	<div>Hello {{ $route.params.id }}</div>' +
					'	<router-view></router-view>' + // 组件中使用路由视图用于渲染子路由匹配到的组件
					'</div>',
			watch: {  // 添加 watch 方法对路由变化作出响应...
				$route:function (to, from) { 
					console.log("route change ",to," <= ",from);
					this.name = to+" <= "+from;
				}
			},
			beforeRouteEnter:function (to, from, next) { // to, from 都是 $route 实例
				console.log("before route enter ", to, " <= ", from);
				next();
			},
			beforeRouteUpdate:function (to, from, next) { // 2.2 中引入的导航守卫
				// react to route changes...
				// don't forget to call next()
				console.log("before route update ", to, " <= ", from);
				next();
			}
		}

		// 2. 配置组件的路由，每个路由应该映射一个组件
		const routes = [
			{ path: '/foo', component: Foo },
			{ path: '/bar', component: Bar, name:"toBar" }, // 设置 name 属性来配置一个命名路由
			{ path: '/user/:id', component: User,  // 动态路径参数 以冒号开头
				children:[ // 嵌套路由 子视图内容会渲染到 User 组件中的 <router-view></router-view>
					{ path:'', component:User }, // 子路由空路径时匹配上一级路由 /user/:id
					{ path:'jeango', component:Foo }, // 匹配 /user/:id/jeango
					{ path:'jimbo',  component:Bar }
				]
			}
		]

		// 3. 以 `routes` 配置创建 router 实例，{ routes } 是ES6缩写，相当于 {routes: routes}
		const router = new VueRouter({ routes:routes })

		// 4. 创建vue实例和挂载根实例。启动应用！
		const app = new Vue({
			router:router,
			data:{name:"Jeango", id:110, stamp: + new Date()},
			watch: { // 监视参数变化
				stamp:function () {
					console.log('watching', this.$route);
					return this.$route.params.name
				}
			},
			methods: {
				goBack:function () {
					this.stamp = +new Date(); // 更新相间数据触发watch事件
					window.history.length > 1
					? this.$router.go(-1)
					: this.$router.push('/')
				}
			}
		}).$mount('#app')

	</script>


## named-route 命名路由
[命名路由](https://router.vuejs.org/zh/guide/essentials/named-routes.html)

通过一个名称来标识一个路由显得更方便一些，特别是在链接一个路由，或者是执行一些跳转的时候。

	const router = new VueRouter({
	  routes: [
	    {
	      path: '/user/:userId',
	      name: 'user',
	      component: User
	    }
	  ]
	})

要链接到一个命名路由，可以给 router-link 的 to 属性传一个对象：

	<router-link :to="{ name: 'user', params: { userId: 123 }}">User</router-link>

这跟代码调用 router.push() 是一回事：

	router.push({ name: 'user', params: { userId: 123 }})

这两种方式都会把路由导航到 `/user/123` 路径。


## named-view 命名视图与嵌套 component vs components
[`<router-view>` Props](https://router.vuejs.org/zh/api/#name)
[命名视图](https://router.vuejs.org/zh/guide/essentials/named-views.html)

如果 `<router-view>` 设置了名称，则会渲染对应的路由配置中 `components` 下的相应组件。查看 命名视图 中的例子。

有时候想同时展示多个视图，而不是嵌套展示，例如创建一个布局，有侧栏导航 sidebar 和主内容 main  两个视图，这个时候命名视图就派上用场了。你可以在界面中拥有多个单独命名的视图，而不是只有一个单独的出口。如果 `router-view` 没有设置名字，那么默认为 `default`。

	<router-view class="view one"></router-view>
	<router-view class="view two" name="a"></router-view>
	<router-view class="view three" name="b"></router-view>

一个视图使用一个组件渲染，因此对于同个路由，多个视图就需要多个组件，确保正确使用 `components` 配置：

	const router = new VueRouter({
	  routes: [
	    {
	      path: '/',
	      components: {
	        default: Foo,
	        a: Bar,
	        b: Baz
	      }
	    }
	  ]
	})

路由可以进行嵌套，相应也可使用命名视图创建嵌套视图的复杂布局。这时你也需要命名用到的嵌套 router-view 组件。我们以一个设置面板为例：

假设 UserSettings 组件的 `<template>` 部分是类似下面的这段代码：

	<!-- UserSettings.vue -->
	<div>
	  <h1>User Settings</h1>
	  <NavBar/>
	  <router-view/>
	  <router-view name="helper"/>
	</div>

然后你可以用这个路由配置完成该布局：

	{
		path: '/settings',
		// 你也可以在顶级路由就配置命名视图
		component: UserSettings,
		children: [
			{ path: 'emails', component: UserEmailsSubscriptions },
			{ path: 'profile', components: {default: UserProfile, helper: UserProfilePreview }
		}]
	}

相应地，对于包含命名视图的路由，要传递参数必须分别为每个命名视图添加 `props` 选项，如果设置为 true，route.params 将会被设置为组件属性，当然也可以设置参数对象：

    {
      path: '/user/:id',
      components: { default: User, subview: Sidebar },
      props: { default: true, subview: false } // subview: {level:2, msg:"foo ..."}
    }


RouteConfig 的类型定义：
	
	declare type RouteConfig = {
	  path: string;
	  component?: Component;
	  name?: string; // 命名路由
	  components?: { [name: string]: Component }; // 命名视图组件
	  redirect?: string | Location | Function;
	  props?: boolean | Object | Function;
	  alias?: string | Array<string>;
	  children?: Array<RouteConfig>; // 嵌套路由
	  beforeEnter?: (to: Route, from: Route, next: Function) => void;
	  meta?: any;
	
	  // 2.6.0+
	  caseSensitive?: boolean; // 匹配规则是否大小写敏感？(默认值：false)
	  pathToRegexpOptions?: Object; // 编译正则的选项
	}


## props 路由组件传参

路由组件的参数传递可以通过 `props` 配置，可以是布尔值、对象或函数。

可以直接通过 `props:true` 开启，这样路由路径 `path` 中设置的参数占位如例子的 `:id` 就会生效，在路由被触发时，参数占位符就会被实际的内容替换。在路由守卫回调函数中就可以访问 route.params 获取参数。路由配置 `props` 还不止这种简单的应用，对于包含命名视图的路由，可以分别为每个命名视图添加 `props` 选项，如下：

	routes: [
	  { path: '/user/:id', component: User, props: true },
	  {
	    path: '/user/:id',
	    components: { default: User, sidebar: Sidebar },
	    props: { default: true, sidebar: false }
	  }
	]

对于多参数的情况，可以使用多个斜杠或其它分隔符隔开，但是注意，如果 `props` 配置为对象或函数，则 `path` 的点位符将不再有效。

    {"path": "/foo/:level/:title", "component": "HelloParagraph", "props": true }, 
	{"path": "/foo/:level|:title", "component": "HelloParagraph", "props": true }, 
	{"path": "/foo/[:level]:title", "component": "HelloParagraph", "props": true }, 

如果参数类型辨识度足够高，分隔符省略不用都可以，如下配置就可以对应 `/foo/2Apple pie` 这个路由地址，并正确提取 `level` 和 `title` 这两个参数，Vue 对应使用的正则表达式如下，可以看到默认的分隔符还是斜杠。如果地址开头中出现两位数字以上的情况，那 `level` 还是只能匹配到一位数值，后面的数字将匹配到 `title` 参数上：

	{"path": "/foo/:level:title", "component": "HelloParagraph", "props": true }, 

	/^\/foo\/((?:[^\/]+?))((?:[^\/]+?))(?:\/(?=$))?$/i


路由配置 `props` 为一个对象，它会被按原样设置为组件属性，当 props 是静态的时候有用。

	const router = new VueRouter({
	  routes: [
	    { path: '/promotion/from-newsletter', component: Promotion, props: { newsletterPopup: false } }
	  ]
	})


配置 `props` 为一个函数，这样你便可以将参数转换成另一种类型，将静态值与基于路由的值结合等等，所以这种方式是最灵活的。

	const router = new VueRouter({
	  routes: [
	    { path: '/search', component: SearchUser, props: (route) => ({ query: route.query.q }) }
	  ]
	})

URL `/search?q=vue` 中的参数将会提取为 `{query: 'vue'}` 属性对象传递给 `SearchUser` 组件。请尽可能保持 props 函数为无状态的，因为它只会在路由发生变化时起作用。如果你需要状态来定义 props，请使用包装组件，这样 Vue 才可以对状态变化做出反应。


## router-view 强制刷新

使用路由视图后，特别是使用动态参数这种情况，由于 Vue 的就地复用规则，路由视图通常是不刷新的，应为复用了就的视图，为了强制刷新视图，只需要给 `router-view` 设置一个唯一的 `key` 属性：

	<transition name="any" mode="in-out" :duration="{enter:100, leave:400}">
		<router-view id="mainView" :key="$route.path"></router-view>
		<router-view id="subView" :key="$route.path" name="secondary"></router-view>
	</transition>

Vue 会根据 `key` 是否相同来决定是否复用视图。


# Vue 响应式基本原理

Vue 实现双向数据绑定的原理就是利用 ECMAScript 5.1 规范中定义的 [Object.defineProperty()] 属性定义接口，这个方法用来定义对象属性描述符。对象属性描述符有**数据描述符**和**存取描述符**。数据描述符是一个具有值的属性，可以配置读写性 `writable`。存取描述符是由 Getter、Setter 函数描述的属性，即对属性读写时的关联函数。描述符必须是这两种形式之一，不能同时是两者，简单地说就是 `get`、`set` 和 `value`、`writable`不能同时定义。这个属性定义接口在 Internet Explorer 9 中才被支持，IE8 虽然实现这个接口但只能在 DOM 对象上使用，这就是 Vue 不支持旧版 IE8 的原因。

当属性设置为 `writable` 为 false 时，该属性处于只读状态，对属性赋值时不会发生错误也不会改变原值。`enumerable` 定义了对象的属性是否可以在 for-in 循环和 Object.keys() 中被枚举，默认为 false。使用 `oo.anotherProperty=123` 这样直接赋值的方式创建对象的属性，则这个属性是可以被枚举的，`enumerable` 为 true。`configurable` 特性表示对象的属性是否可以被重新配置，以及除 `value` 和 `writable` 特性外的其他特性是否可以被修改，也就是说，当属性定义为不可配置时，对 `enumerable` 或 Getter、Setter 方法重新定义时会抛出异常。

```javascript
	var oo = { _value:1 };
	Object.defineProperty(oo,'value', {
		// value:9,
		// writable: false,
		enumerable: true,
		configurable: true,
		get: function(){
			console.log("get value...", this._value);
			return this._value;
		},
		set: function(value){
			this._value = value;
			console.log(`set value... ${this._value}`);
		}
	});

	var i = oo.value;
	oo.value += 1;
```

Vue 实现数据绑定的做法是通过 [Object.defineProperty()] 劫持数据，再通过 Publish–Subscribe Pattern 发布-订阅开发模式来管理数据变化，发布-订阅模式中 Vue 充当了发布者 ，Watcher、Computed 设置的方法则是订阅者，同时又是，Vue 劫持数据监听到数据变更时对订阅者发起调用通知数据更新。监听到 data 的数据有变化时，Vue 还会判断数据是否是原有数据对象的引用，如果不是则进入视图更新流程，用新数据渲染，这就是 Vue MVVM 原理。这个过程中 Vue 还使用了 观察者模式 Observer Pattern，和发布-订阅模式一样，都用来降低耦合度。发布订阅模式里，发布者和订阅者，不是松耦合，而是完全解耦的。相对 Watcher 来说，Vue 对计算属性 Computed 处理显得更像观察模式，即观察者通过观察计算属性中被依赖的数据来进行响应。而发布订阅模式里，除了发布者和订阅者两个角色，还有经常被忽略的经纪人 Broker，只是这个角色在代码实现上不太明显有独立模块实现。

计划 2019 年更新的 Vue.js 3.0 会启用新特性，将使用 ES6 的 Proxy 作为其观察者机制，取代之前使用的目前使用的 Object.defineProperty，[Vue3.0 尝鲜 defineProperty VS Proxy]。

[Vue3.0 尝鲜 defineProperty VS Proxy]: https://mp.weixin.qq.com/s/wQf1QiMdx-As78CC3s1iYg
[Proxy 对象代理参考文档]: https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Proxy
[Reflect 文档]: https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Reflect

Proxy 对象用于定义基本操作的自定义行为，如属性查找，赋值，枚举，函数调用等。通过 Proxy 对象可以劫持整个被代理的对象，支持 13 种劫持操作，可以实现真正的私有成员！但 Proxy 是 es6 提供的新特性，兼容性不好，也无法用 polyfill 来兼容，所以新版的 Vue 3.0 计划只支持 IE 11。Proxy 和 PHP 的魔术方法 Magic Methods 机制是类似的，这是动态语言的便利之处，如果在性能上不太消耗资源，这种便利还是可取的。参考 [Proxy 对象代理文档]。

	let obj = {};
	let handler = {
	    get(target, key) {
	        console.log(`read ${key}`);
	        return key in target ? target[key] : 3;
	    },
	    set(target, key, value) {
	        console.log(`set ${key}=${value}`);
	        target[key] = value;
	    }
	}
	let p = new Proxy(obj, handler);
	p.name = 'tom'; // set name=tom
	var i = p.age; // read age
	console.log("age", i); // age 3

还有一个紧密相关的 Refect 也是 Es6 的新特性，与大多数全局对象不同，Reflect 没有构造函数。你不能将其与一个 new 运算符一起使用，或者将 Reflect 对象作为一个函数来调用。Reflect 的所有属性和方法都是静态的，就像 Math 对象，参考 [Reflect 文档]。

在 Proxy 内部调用对象的默认行为就需要 Reflect，它就是 ES6 为了操作对象而提供的新 API。Reflect 对象一共有 13 个静态方法，匹配 Proxy 13 种拦截行为。

// 如果遇到 getter，receiver 将提供给目标调用。
// 如果遇到 setter，this 将提供给目标调用。

	const arr = [];
	const newArr = new Proxy(arr, {
	    get: function(target, key, receiver) {
	        console.log(`read target`);
	        return Reflect.get(target, key, receiver);
	    },
	    set: function(target, key, value, receiver) {
	        console.log("target=", target, `target[${key}]=${value}`, receiver);
	        return Reflect.set(target, key, value, receiver);
	    }
	});

	newArr[1] = 9;

输出内容，前六行内容是 console.log() 中读取了 receiver 引起的：

	read target
	read target
	read target
	read target
	read target
	read target
	target= [] target[1]=9 []

Proxy 与 Reflect 方法对应，Proxy 还提供了 `revocable(target, handler)` 方法来创建一个可撤销的代理对象：

	Reflect.apply(target, thisArg, args)             handler​.apply()
	Reflect.construct(target, args)                  handler​.construct()
	Reflect.get(target, name, receiver)              handler​.get()
	Reflect.set(target, name, value, receiver)       handler​.set()
	Reflect.defineProperty(target, name, desc)       handler​.define​Property()
	Reflect.deleteProperty(target, name)             handler​.delete​Property()
	Reflect.has(target, name)                        handler​.has()
	Reflect.ownKeys(target)                          handler​.own​Keys()
	Reflect.isExtensible(target)                     handler​.isExtensible()
	Reflect.preventExtensions(target)                handler​.prevent​Extensions()
	Reflect.getOwnPropertyDescriptor(target, name)   handler​.get​OwnProperty​Descriptor()
	Reflect.getPrototypeOf(target)                   handler​.get​PrototypeOf()
	Reflect.setPrototypeOf(target, prototype)        handler​.set​PrototypeOf()



# Vue errorHandler

[优雅的处理vue项目异常]: https://juejin.im/post/5cf72029f265da1b5f264334

全局异常捕获

	Vue.config.errorHandler = function (err, vm, info) {
	  // 指定组件的渲染和观察期间未捕获错误的处理函数。这个处理函数被调用时，可获取错误信息和 Vue 实例。
	  
	  // handle error
	  // `info` 是 Vue 特定的错误信息，比如错误所在的生命周期钩子
	  // 只在 2.2.0+ 可用  
	}

注意：面对异常处理，同步异常和异步异常应该区别对待分别处理。

通过阅读源码看一下vue是如何将Vue.config.errorHandler接口暴露给使用者。

## 同步异常处理方案

	// 定义异常处理函数，判断用户是否自定义Vue.config.errorHandler，定义则直接调用，未定义执行vue本身异常处理。
	function globalHandleError(err, vm, info) {
	  if (Vue.config.errorHandler) {
	    try {
	      return config.errorHandler.call(null, err, vm, info)
	    } catch (e) {
	      logError(e, null, 'config.errorHandler');
	    }
	  }
	  logError(err, vm, info);
	}
	try {
	  // vue正常执行代码被包裹在try内，有异常会调用globalHandleError
	} catch (e) {
	  globalHandleError(e, vm, '对应信息');
	}

## 异步异常处理方案

	// 定义异步异常处理函数，对于自身没有捕获异常的promise统一执行catch
	function invokeWithErrorHandling(
	  handler,
	  context,
	  args,
	  vm,
	  info
	) {
	  var res;
	  try {
	    res = args ? handler.apply(context, args) : handler.call(context);
	    if (res && !res._isVue && isPromise(res) && !res._handled) {
	      res.catch(function (e) { return handleError(e, vm, info + " (Promise/async)"); });
	      // 异步代码例如promise可以统一为其定义Promise.prototype.catch()方法。
	      res._handled = true;
	    }
	  } catch (e) {
	    handleError(e, vm, info);
	  }
	  return res
	}

	// 所有的钩子函数调用异常处理函数
	function callHook(vm, hook) {
	  var handlers = vm.$options[hook];
	  // 为所有钩子增加异常处理
	  var info = hook + " hook";
	  if (handlers) {
	    for (var i = 0, j = handlers.length; i < j; i++) {
	      invokeWithErrorHandling(handlers[i], vm, null, vm, info);
	    }
	  }
	}


## 知识延伸

	// vue接口是能处理同步异常以及部分钩子中的异步异常，对于方法中的异常无法有效处理，我们可以仿照源码增加方式中的异步异常处理，避免为每一个promise写catch
	Vue.mixin({
	  beforeCreate() {
	    const methods = this.$options.methods || {}
	    Object.keys(methods).forEach(key => {
	      let fn = methods[key]
	      this.$options.methods[key] = function (...args) {
	        let ret = fn.apply(this, args)
	        if (ret && typeof ret.then === 'function' && typeof ret.catch === "function") {
	          return ret.catch(Vue.config.errorHandler)
	        } else { // 默认错误处理
	          return ret
	        }
	      }
	    })
	  }
	})

下面是全局处理异常的完整代码，已经封装成一个插件

	/**
	 * errorPlugin.js
	 * 全局异常处理
	 * @param {
	 * } error 
	 * @param {*} vm 
	 */
	const errorHandler = (error, vm, info) => {
	  console.error('抛出全局异常')
	  console.error(vm)
	  console.error(error)
	  console.error(info)
	}
	let GlobalError = {
	  install: (Vue, options) => {
	  /**
	   * 全局异常处理
	   * @param {
	   * } error 
	   * @param {*} vm 
	   */
	    Vue.config.errorHandler = errorHandler
	    Vue.mixin({
	      beforeCreate() {
	        const methods = this.$options.methods || {}
	        Object.keys(methods).forEach(key => {
	          let fn = methods[key]
	          this.$options.methods[key] = function (...args) {
	            let ret = fn.apply(this, args)
	            if (ret && typeof ret.then === 'function' && typeof ret.catch === "function") {
	              return ret.catch(errorHandler)
	            } else { // 默认错误处理
	              return ret
	            }
	          }
	        })
	      }
	    })
	    Vue.prototype.$throw = errorHandler
	  }
	}
	export default GlobalError


	// 在入口文件中引入
	import ErrorPlugin from './errorPlugin'
	import Vue from 'vue'
	Vue.use(ErrorPlugin)

## 写在最后

增加全局异常处理有助于

提高代码健壮性
减少崩溃
快速定位bug


# Vuex 状态管理插件

[Vuex 官方文档](https://vuex.vuejs.org/zh/)

Vuex 是一个专为 Vue.js 应用程序开发的状态管理模式。引入 Vuex 状态管理，Vue 组件需要获取或更改状态数据时通过触发事件或动作 `Actions` 的方式告知 Vuex，在 `Actions` 中定义的方法响应需求，并将数据操作提交到 Vuex 内部集中处理，通过定义在 `Mutations` 中的数据操作方法修改保存在状态仓库 `store` 中的数据, 前缀 Mut 表示 Mutiple 多个的意思。当 State 中的数据被改变之后，Vue 会检测到数据变化并重新渲染到组件中去，组件展示更新后的数据，完成一个流程。

Vuex 的核心是仓库 Store，相当于是一个容器，一个 Store 实例中包含以下属性的方法：

+ state 定义属性（状态 、数据）
+ getters 用来获取属性
+ actions 定义方法（动作）
+ commit 提交变化，修改数据的唯一方式就是显示的提交 mutations
+ mutations 定义变化，处理状态（数据）的改变
+ mapGetters 用来获取属性（数据）
+ mapActions 用来获取方法（动作）

接下来写个DEMO理解 vuex，首先在vue工程目录下执行 npm 命令安装 vuex

	npm install vuex -S

这个命令会下载 Vuex 到工程目录的 node_modules\vuex 目录下，并修改根目录下的 package.json 配置文件，将 Vuex 添加到依赖项列表中。

创建 store.js 模块文件作为数据仓库，引入 Vuex 并安装到 Vue，用 state 对像保存定义属性，用它初始化创建一个 Vuex.Store 对象然后导出。以下代码使用了 ES6 的对象解构语法，和 {obj1,obj2} 这种写法一样，函数可以表达为 {count:function(state){...}} 就可以简化成 {count(state){...}} 自行补课。

	import Vue from 'vue'
	import Vuex from 'vuex'
	Vue.use(Vuex)

	var state = {
	    count:0
	}

	var getters = {
	    count(state){
	        return state.count
	    }
	}

	const actions = {
	    increment({commit,state}){
	        commit('increment') 
	    }
	}

	const mutations = {
	    increment(state){
	        state.count ++;
	    }
	}

	const store = new Vuex.Store({ state, getters, actions, mutations })

	export default store;

在入口文件 main.js 中导入上面建立的数据仓库并配置到 Vue 实例中，Vue会自动将 store 对象注入到所有子组件中，在子组件中通过 this.$store 访问该 store 数据仓库。`{store,el:'#app'}` 这写法是ES6的精简表达式，等于 `{store:store, el:"#app"}`。

	import Vue from 'vue'
	import App from './App.vue'
	import store from './store'

	new Vue({
	  store, 
	  el: '#app',
	  render: h => h(App)
	})

在 app.vue 组件中引入也相应引入 `mapGetters` 和 `mapActions` 辅助函数，并用 `mapActions` 来包装数据仓库 store.js 导出的 `increment` 方法。在计算属性中调用 `mapGetters` 辅助方法，并传入一个数组，在数组中指定要获取的属性，此例子只有 `count` 这个数据属性。

	<template>
		<div id="app">
			<button @click="increment">增加</button>
			<button>减少</button>
			<h1>{{count}}</h1>
		</div>
	</template>

	<script>
	import {mapGetters,mapActions} from 'vuex'
	export default {
		name: 'app',
		computed:mapGetters([
			'count'
		]),
		methods:mapActions([
			'increment',
		])
	}
	</script>

在组件调用 increment 动作，就是执行数据仓库导出相应方法，然后通过 commit 将动作提交到 mutations 处理。



# CORS 跨域问题

阮一峰老师跨域资源共享 CORS 详解：   
http://www.ruanyifeng.com/blog/2016/04/cors.html
http://www.cnblogs.com/xuange306/p/6185453.html

CORS是一个W3C标准，全称是"跨域资源共享"（Cross-origin resource sharing）。
  
它允许浏览器向跨源服务器，发出 XMLHttpRequest 请求，从而克服了AJAX只能同源使用的限制。

在开发阶段可以通过禁止浏览器安全选项实现，增加启动参数，在目标后面增加如下的启动参数：

	”chrome.exe" --user-data-dir="c:\ChromeDebug" --test-type --disable-web-security
	"chrome.exe" --remote-debugging-port=9222 --test-type --disable-web-security

表示 Chrome 会从 C:\ChromeDebug 中存取用户数据，因该目录可能为空，所以新打开的 Chrome-Debug 窗口是一个全新的 Chrome，没有书签、历史、扩展程序等内容，需要再重新安装扩展程序。

在服务器端直接输出 CORS 头是最直接的解决办法：

	res.header('Access-Control-Allow-Origin', 'http://localhost:5080');
	// * 这个表示任意域名都可以访问，这样写不能携带cookie了。 || 'http://localhost:5080'
	res.header('Access-Control-Allow-Credentials', true);
	// 允许服务器端发送Cookie数据,
	// 若前端设置了 axios.defaults.withCredentials = true
	// 则必须相应设置 Access-Control-Allow-Credentials=true 否则会请求失败、报错
	res.header('Access-Control-Allow-Headers', 'Content-Type, Content-Length, Authorization, Accept, X-Requested-With , yourHeaderFeild');
	//它也是一个逗号分隔的字符串，表明服务器支持的所有头信息字段
	res.header('Access-Control-Allow-Methods', 'PUT, POST, GET, DELETE, OPTIONS');


## Express CORS Server

[Express.js API]: http://www.expressjs.com.cn/4x/api.html#app.all
[Node cors package]: https://www.npmjs.com/package/cors	
[Express Middleware]: http://www.expressjs.com.cn/resources/middleware.html

利用 Node.js + Express 可以快速搭建一个用于开发的代理服务器，参考代码如下，保存到 `cors_dev.js` 然后通过 node 执行它即可以运行这个用于开发的代理服务器，结果 Node 的 HTTP 模块还可以访问其它服务器的资源：

	node cors_dev.js

Vue CLI 3 项目默认安装好 Express，其它没有安装的模块，在项目目录下执行 npm 安装命令进行安装，使用到的中间件如 cors 的使用方法参考 [Express Middleware]：

	npm install cors
	npm install morgan

顶级 express 对象提供的 `Router()` 方法可以创建 `router` 对象。的路由中间件 `router` 可以视为 Express 的一个路由分支，可以看作一个应用程序，它的目的是中间件和路由的分离的实例。和 Express 应用一样，可以通过 `get()`、`post()` 等等方法设置路由及响应方法。

Express 默认使用 jade 模板，可以配置让其支持使用 ejs 或 html 模板，渲染模板使用 `render()` 方法，模板文件存放于 `views` 目录下。Express 实例的 `set()` 方法有一项是 `view engine`，在没有指定文件模板格式时，设置默认使用的引擎插件。

当一个路由匹配命中后，就会执行相应的回调函数来响应浏览器。`all("*")` 表示匹配所有可能，但它定义在最后面，只响应前面那些路由没有匹配时的情况。

输出 CORS 头信息可以直接使用 Express 的 `header()` 方法，也可以在路由方法中直接使用 `cors()` 方法，如例中的 `/hello` 和 `/vue/config` 两个路由地址。使用方法参考官方文档 [Express.js API] & [Node cors package]。

	var express = require("express");
	var cors = require("cors");
	var path = require("path");
	var logger = require("morgan");
	var ejs = require('ejs');
	var https = require('https');
	var http = require('http');	
	// var favicon = require("favicon");
	// var cookieParser = require("cookie-parser");
	// var bodyParser = require("body-parser");

	var router = express.Router();
	router.get('/', (req, res, next)=>{
	  res.render('index.html', {title:"Express Web Server。", BASE_URL:"/"});
	  res.send("Express Web: GET /");
	});
	router.get('/vue/config', cors(), (req, res, next)=>{
	  
	  res.json({state:"ok", config:"TODO..."});
	});
	router.post('/', (req, res, next)=>{
	  res.json({title:"Express Web Server!"});
	});
	// module.exports = router

	var app = express();
	app.engine('html', ejs.__express);
	app.set('view engine', 'html');
	app.use("/", router);
	app.get('/hello', cors(), (req, res) => res.send('Hello World!'));
	app.use(logger("common")); // combined:Standard Apache combined log output. 
	app.use(cors({
	    origin:['http://localhost:80','*'],
	    methods:['GET','POST'],
	    alloweHeaders: ['Access-Control-Allow-Origin', 'Conten-Type', 'Authorization']
	}));

	app.all("*", function (req, res, next) {
	  res.header("Access-Control-Allow-Credentials", "true");
	  res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
	  res.header("Access-Control-Allow-Origin", "*");
	  res.header("Access-Control-Allow-Methods", "PUT,POST,GET,DELETE,OPTIONS");
	  res.send('Express...');
	  next();
	});

	app.listen(3000, () => console.log('Example app listening on port 3000!'))

如果系统安装了 curl 工具，可以直接使用命令查看 CORS 头信息是否已经设置好：

	curl -v -I -H "Origin: https://github.com" http://localhost:3000/

开发过程会需要动态加载配置模块，但 require 具有缓存功能，加载一次后就会直接在内容读取，为了动态加载，需要清除 require.cache 缓存的内容，可以通过以下方法实现。

	function fresh_require(path){
	  delete require.cache[require.resolve(path)];
	  console.log("clear require.cache", require.resolve(path));
	  return require(path);
	}

也可以使用 Express 提供的原生中间件函数 express.static 中间件来托管静态文件，包括图片、CSS 以及 JavaScript 文件。

	app.use(express.static('public'));


# Transitions 组件与 Tween 过渡动效

[进入/离开 & 列表过渡]: https://cn.vuejs.org/v2/guide/transitions.html
[状态过渡]: https://cn.vuejs.org/v2/guide/transitioning-state.html
[GreenSock]: https://greensock.com/
[GreenSock CDN]: https://cdnjs.com/libraries/gsap
[GreenSock-JS]: https://github.com/greensock/GreenSock-JS
[HTML5 Ease Animation Visualizer for GSAP]: https://greensock.com/ease-visualizer
[Animate.css]: https://daneden.github.io/animate.css/
[FLIP]: https://aerotwist.com/blog/flip-your-animations/


## 过渡组件与关联样式

Vue 的 transition 组件可以在下列情形中给任何元素和组件添加进入/离开过渡，Vue 官方文档中的过渡这个词和缓动 Tween 或 Transition 是等价的。

+ 条件渲染 (使用 `v-if` 指令)
+ 条件展示 (使用 `v-show` 指令)
+ 动态组件
+ 组件根节点

包含在过渡组件 `transition` 内的元素在视图响应数据更新，需要插入或删除时，Vue 将会做以下处理：

+ 自动嗅探目标元素是否应用了 CSS 过渡或动画，如果是，在恰当的时机添加/删除 CSS 类名。
+ 如果过渡组件提供了 JavaScript 钩子函数，这些钩子函数将在恰当的时机被调用。
+ 如果没有找到 JavaScript 钩子并且也没有检测到 CSS 过渡/动画，DOM 插入或删除等操作会在下一帧中立即执行，此帧指浏览器逐帧动画机制。

与过渡过程相关的样式类有 6 个，与之对应的过渡状态动画帧如下，带有 `enter` 的类应用在将要插入的新组件上，带有 `leave` 的类应用在将要被移除的组件上。注意 **v-enter** 和 **v-leave** 这两个过渡类有效时间是很短暂的，不能用来设置时效样式，进入过渡的过程时间，延迟和曲线函数等等可以在 `v-enter-to` 和 `v-leave-to` 样式类中设置：

0. 过渡状态开始，对应样式类 **v-enter-active**、**v-enter**
0. 新元素被插件，对应样式类 **v-enter-active**、**v-enter-to**
0. 已经进入过渡，对应样式类 **v-enter-active**、**v-enter-to**
0. 过渡状态完成，对应样式类被移除。

0. 过渡状态离开，对应样式类 **v-leave-active**、**v-leave** 
0. 已经离开过渡，对应样式类 **v-leave-active**、**v-leave-to**、
0. 已经进入过渡，对应样式类 **v-leave-active**、**v-leave-to**
0. 过渡状态完成，对应样式类被移除。

+ **v-enter** 定义进入过渡的开始状态。在元素被插入之前生效，在元素被插入之后的下一帧移除。
+ **v-enter-active** 定义进入过渡生效时的状态。在整个进入过渡的阶段中应用，在元素被插入之前生效，在过渡动画完成之后移除。这个类可以被用来定义进入过渡的过程时间，延迟和曲线函数。
+ **v-enter-to** Vue 2.1.8+ 定义进入过渡的结束状态。在元素被插入之后下一帧生效 (与此同时 v-enter 被移除)，在过渡/动画完成之后移除。
+ **v-leave** 定义离开过渡的开始状态。在离开过渡被触发时立刻生效，下一帧被移除。
+ **v-leave-active** 定义离开过渡生效时的状态。在整个离开过渡的阶段中应用，在离开过渡被触发时立刻生效，在过渡/动画完成之后移除。这个类可以被用来定义离开过渡的过程时间，延迟和曲线函数。
+ **v-leave-to** Vue 2.1.8+ 定义离开过渡的结束状态。在离开过渡被触发之后下一帧生效 (与此同时 v-leave 被删除)，在过渡/动画完成之后移除。

例如以下例子中，过渡组件使用了 `name` 属性，过渡样式类前缀 `v-` 就会替换为 `mytween-`，Vue 会尝试在组件的样式定义中检测是否有相关的过渡样式定义：

	<div id="demo">
	  <button v-on:click="show = !show"> Toggle </button>
	  <transition name="mytween">
	    <p v-if="show">hello</p>
	  </transition>
	</div>

	new Vue({
	  el: '#demo',
	  data: { show: true }
	})

	.mytween-enter-active, .mytween-leave-active {
	  transition: opacity .5s;
	}
	.mytween-enter, .mytween-leave-to {
	  opacity: 0;
	}

除了以上 Vue 内部预置过渡类，还可以在 `transition` 组件属性指明自定义过渡的类名，这些属性定义如下：

+ enter-class
+ enter-active-class
+ enter-to-class (2.1.8+)
+ leave-class
+ leave-active-class
+ leave-to-class (2.1.8+)

	<transition enter-active-class="animated tada" leave-active-class="animated bounceOutRight">
		<p v-if="show">hello</p>
	</transition>

他们的优先级高于普通的类名，方便和第三方 CSS 动画库，如 [Animate.css] 结合使用。一旦设置自定义过渡样式类后，Vue 将不再侦测相应的样式，而是直接使用自定义样式类。

Vue 2.2.0 新增 `duration` 特性，可以编排的一系列过渡效果，其中一些嵌套的内部元素相比于过渡效果的根元素有延迟的或更长的过渡效果。
在这种情况下你可以用 `<transition>` 组件上的 `duration` 属性定制一个显性的过渡持续时间，可以定制进入和移出的持续时间，单位毫秒：

	<transition :duration="1000">...</transition>
	<transition :duration="{ enter: 500, leave: 800 }">...</transition>

## 列表过渡动效

多个组件的过渡可以结合 Vue 内置的动态组件来实现，简单很多，也不需要使用 key 特性：

	<transition name="component-fade" mode="out-in">
	  <component v-bind:is="view"></component>
	</transition>

对于使用 v-for 渲染的整个列表，在这种场景中使用 `<transition-group>` 组件。不同于 `<transition>`，它会以一个真实元素呈现，默认为一个 `<span>`，通过 `tag="span"` 特性更换为其他元素。 过渡模式在此不可用，因为不再相互切换特有的元素。其内部元素，总是需要提供唯一的 key 属性值，否则不能识别并正确使用动效。

Vue 文档中提供了一个缓动示例，使用了一种叫 [FLIP] 简单的动画队列，[FLIP] 主要解决的是动画平滑问题，可以达到 60FPS 的动画就是视觉平滑的。通过使用 transforms 将元素从之前的位置平滑过渡新的位置。通过 transition 样式来控制 transform 的时效，以下任一条样式会使用变换样式整个动效时间延长为 10 秒，all 用来匹配所有样式属性，包括 transform：

    transition: transform 10s;
    transition: all 10s;

文档中结合回调函数的动画过渡示例代码如下：

	<script src="https://cdn.staticfile.org/vue/2.2.2/vue.min.js"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/lodash.js/4.14.1/lodash.min.js"></script>

	<div id="list-complete-demo" class="demo">
	  <button v-on:click="shuffle">Shuffle</button>
	  <button v-on:click="add">Add</button>
	  <button v-on:click="remove">Remove</button>
	  <transition-group name="list-complete" tag="p">
	    <span v-for="item in items" v-bind:key="item" class="list-complete-item">
	      {{ item }}
	    </span>
	  </transition-group>
	</div>

	<script>
	new Vue({
	  el: '#list-complete-demo',
	  data: {
	    items: [1,2,3,4,5,6,7,8,9],
	    nextNum: 10
	  },
	  methods: {
	    randomIndex: function () {
	      return Math.floor(Math.random() * this.items.length)
	    },
	    add: function () {
	      this.items.splice(this.randomIndex(), 0, this.nextNum++)
	    },
	    remove: function () {
	      this.items.splice(this.randomIndex(), 1)
	    },
	    shuffle: function () {
	      this.items = _.shuffle(this.items)
	    }
	  }
	})
	</script>
	
	<style>
	.list-complete-item {
	  transition: all 1s;
	  display: inline-block;
	  margin-right: 10px;
	}
	.list-complete-enter, .list-complete-leave-to {
	  opacity: 0;
	  transform: translateY(30px);
	}
	.list-complete-leave-active {
	  position: absolute;
	}		
	</style>

这里使用了 [Lodash]，它是一个原生库没有依赖，通过丰富数组，数字，对象，字符串等功能方法，使 JavaScript 变得更简单易用，通过下划线使用它定义好的方法，对比以下两行代码会发现它的便利性，参考 [Lodash 中文文档]：

    console.log(Math.floor(Math.random() * (20 - 15)) + 15);
    console.log(_.random(15, 20));

[Lodash]: https://lodash.com/docs/4.17.11
[Lodash 中文文档]: https://www.html.cn/doc/lodash/



## 过渡与回调函数

Vue 为了知道过渡的完成，必须设置相应的事件监听器。它可以是 transitionend 或 animationend ，这取决于给元素应用的 CSS 规则。如果你使用其中任何一种，Vue 能自动识别类型并设置监听。

但是，在一些场景中，你需要给同一个元素同时设置两种过渡动效，比如 animation 很快的被触发并完成了，而 transition 效果还没结束。在这种情况中，你就需要使用 type 特性并设置 animation 或 transition 来明确声明你需要 Vue 监听的类型。


可以在属性中声明 JavaScript 钩子，这些钩子函数可以结合 CSS transitions/animations 使用，也可以单独使用。当结合 CSS 使用时 `enter()`、`leave()` 回调函数的 done 是可选的，另外 `leaveCancelled()` 只用于 v-show 中。

	<transition
	  v-on:before-enter="beforeEnter"
	  v-on:enter="enter"
	  v-on:after-enter="afterEnter"
	  v-on:enter-cancelled="enterCancelled"

	  v-on:before-leave="beforeLeave"
	  v-on:leave="leave"
	  v-on:after-leave="afterLeave"
	  v-on:leave-cancelled="leaveCancelled"
	> <!-- ... --> </transition>

	// ...
	methods: {
	  beforeEnter:    function (el) { ... },
	  enter:          function (el, done) { ... done() },
	  afterEnter:     function (el) { ... },
	  enterCancelled: function (el) { ... },

	  beforeLeave:    function (el) { ... },
	  leave:          function (el, done) { ... done() },
	  afterLeave:     function (el) { ... },
	  leaveCancelled: function (el) { ... }
	}

当只用 JavaScript 过渡的时候，在 enter 和 leave 中必须使用 done 进行回调。否则，它们将被同步调用，过渡会立即完成。

推荐对于仅使用 JavaScript 过渡的元素添加 v-bind:css="false"，Vue 会跳过 CSS 的检测。这也可以避免过渡过程中 CSS 的影响。


## 过渡与初始渲染

可以通过 `appear` 特性设置节点在初始渲染的过渡，和进入、离开过渡一样，也可以自定义 CSS 类名和回调函数：

	<transition
	  appear
	  appear-class="custom-appear-class"
	  appear-to-class="custom-appear-to-class" (2.1.8+)
	  appear-active-class="custom-appear-active-class"
	  v-on:before-appear="customBeforeAppearHook"
	  v-on:appear="customAppearHook"
	  v-on:after-appear="customAfterAppearHook"
	  v-on:appear-cancelled="customAppearCancelledHook"
	> <!-- ... --> </transition>

在上面的例子中，无论是 `appear` 特性还是 `v-on:appear` 钩子都会生成初始渲染过渡。


## 与其它动效库整合

Vue 的过渡系统提供了非常多简单的方法设置进入、离开和列表的动效。对于数据比如数字和运算、 颜色的显示、 SVG 节点的位置、 元素的大小和其他的属性，可以结合 Vue 的响应式和组件系统，使用第三方缓动库如 [GreenSock] 来实现切换元素的过渡状态，这是一个专业级动效库，页面可以直接通过 [GreenSock CDN] 引用，核心库分为 TweenMax 和轻量版 TweenLite，而 TimelineLite 和 TimelineMax 这两个则是实现时间轴动效的扩展核心，通过时间轴动效可以实现诸如暂停 `pause()`、复原 `resume()`、快进 `seek(1.5)`、 倒放 `reverse()` 等等效果。另外还有一众插件如贝塞尔曲线 BezierPlugin，通过它可以构造复杂的动画路径，还有内置常用的缓动 Core Eases 包括：

+ Linear
+ Power0
+ Power1 对应曲线 Quad
+ Power2 对应曲线 Cubic
+ Power3 对应曲线 Quart
+ Power4 对应曲线 Strong、Quint

贝塞尔曲线 Bezier 是非常有用的一种曲线表达方式，只用四个端点就可以构造出千变万化的曲线。在 Chrome 浏览器的开发者工具上提供了一个小面板工具可以用来获取贝塞尔曲线的四个端点坐标。通过 `F12` 打开开发者工具，进入 `Elements` 面板，选择其中的一个 DOM 节点如 `body`，为其它添加一个动画样式 `animation: any 1s ease`，这个动画样式中的 `ease` 就是一种最常用的缓动曲线，添加这个动画样式后，`ease` 会变成一个曲线图标按钮，点击它就可以看到一个贝塞尔曲线调整面板，这个面板中将两个端点固定，只能在 `[0,1]` 区间调整另外两活动端点，这个值可以作为比例值来使用。被固定的两个端点坐标对应以下代码中的 `points` 的第一个和最后一个元素，通过调整中间两个活动锚点就可以得到各种缓动曲线，GreenSock 官方也提供了可视化的缓动演示，戳这 [HTML5 Ease Animation Visualizer for GSAP]。

	<script src="https://cdnjs.cloudflare.com/ajax/libs/gsap/2.1.2/TweenMax.min.js"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/gsap/2.1.2/plugins/BezierPlugin.min.js"></script>

	<div id="demo" style="width:60px;background: pink; font-size:30px; animation:any 1s ease;">DE MO!</div>

	<script>
	var points = [{x:0, y:0}, {x:0, y:660}, {x:660, y:0}, {x:540, y:540}];
	var demo = document.getElementById("demo");
	TweenMax.to(demo, 5, {bezier:{type:"cubic", values:points, autoRotate:["x","y","rotation",45,false]}, ease:Power1.easeInOut});
	</script>


项目托管源代码下载 [GreenSock-JS]，下面例子演示了 `TweenLite.to()` 动效方法实现数值的缓动。

	<script src="https://cdn.staticfile.org/vue/2.2.2/vue.min.js"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/gsap/1.20.3/TweenMax.min.js"></script>
	<script src="https://cdn.staticfile.org/vue/2.2.2/vue.min.js"></script>

	<div id="animated-number-demo">
	  <input v-model.number="number" type="number" step="20">
	  <p>{{ animatedNumber }}</p>
	</div>

	new Vue({
	  el: '#animated-number-demo',
	  data: {
	    number: 0,
	    tweenedNumber: 0
	  },
	  computed: {
	    animatedNumber: function() {
	      return this.tweenedNumber.toFixed(0);
	    }
	  },
	  watch: {
	    number: function(newValue) {
	      TweenLite.to(this.$data, 0.5, { tweenedNumber: newValue });
	    }
	  }
	})

对于不能直接像数字一样存储的值，比如 CSS 中的 color 的值，可以使用不同的色彩模型来进行渐变，例如将 RGB 模型转换到 HSL 模型就可以很好的对色彩、饱和度或亮度进行单独的缓变调整，也可以使用 [Tween.js] 和 [Color.js] 这些库来实现渐变，Vue 官方文档有关于这部分的例子，戳这[状态过渡]。[Velocity.js] 也是不错的一个，除了在色彩渐变效果上，因为它是在 RGB 色彩模型上进行效果处理的，需要对 RGB 单色通道进行控制，效果比较粗糙。现代的浏览器对 SVG 支持都比较全面，所以可以考虑使用 SVG 来实现一些动画效果，SVG 的本质是数据，点坐标线段是构成 SVG 图案的基本数据，Vue 很擅长数据的处理。需要注意的是，SVG 动画是非学消耗资源的，所以不要滥用。

[Tween.js]: https://github.com/tweenjs/tween.js
[Color.js]: https://github.com/brehaut/color-js
[Velocity.js]: http://www.velocityjs.org/


# 整合 TinyMCE 编辑器
https://www.tiny.cloud/docs/integrations/vue/

Installation

	$ npm install @tinymce/tinymce-vue

Loading the component

First you have to load the component and how you do this depends on how the app you are developing is set up. If you are using some kind of bundle loader like webpack, rollup or browserify you can add the import like this:

	// es modules
	import Editor from '@tinymce/tinymce-vue';
	// commonjs require
	// NOTE: default needed after require
	var Editor = require('@tinymce/tinymce-vue').default;

If you aren’t using a module loader and just adding the javascript file imports to your html files you will have to copy the tinymce-vue.min.js file, found in the lib/browser folder of the npm package, to your app and add something like this:

	<script src="path/to/tinymce-vue.min.js"></script>

You can then add the editor to the components property of your app:

	// This might look different depending on how you have set up your app
	// but the important part is the components property
	var app = new Vue({
	  el: '#app',
	  data: { /* Your data */ },
	  components: {
	    'editor': Editor // <- Important part
	  },
	  methods: { /* Your methods */}
	})

Using the component in your templates
Use the editor in your templates like this:

	<editor api-key="API_KEY" :init="{plugins: 'wordcount'}"></editor>

Configuring the editor

The editor accepts the following props:

`disabled`: Using this prop that takes a boolean value you can dynamically set the editor into a “disabled” readonly mode or into the normal editable mode.
`id`: An id for the editor so you can later grab the instance by using the tinymce.get('ID') method on tinymce, defaults to an automatically generated uuid.
`init`: Object sent to the tinymce.init method used to initialize the editor.
`initial`-value: Initial value that the editor will be initialized with.
`inline`: Shorthand for setting that the editor should be inline, `<editor inline></editor>` is the same as setting {inline: true} in the init.
`tag-name`: Only used if the editor is inline, decides what element to initialize the editor on, defaults to div.
`plugins`: Shorthand for setting what plugins you want to use, `<editor plugins="foo bar"></editor>` is the same as setting {plugins: 'foo bar'} in the init.
`toolbar`: Shorthand for setting what toolbar items you want to show, `<editor toolbar="foo bar"></editor>` is the same as setting {toolbar: 'foo bar'} in the init.
`model-events`: Change on what events you want to trigger the v-model events, defaults to 'change keyup'.
`api-key`: Api key for TinyMCE cloud, more info below.
`cloud-channel`: Cloud channel for TinyMCE Cloud, more info below.

None of the configuration props are required for the component to work - other than if you are using TinyMCE Cloud you will have to specify the api-key to get rid of the This domain is not registered... warning message.

You can also use the v-model directive on the editor to create a two-way data binding:

	<editor v-model="content"></editor>

Event binding

	<editor @onSelectionChange="handlerFunction"></editor>

All available events

	`onActivate` `onAddUndo` `onBeforeAddUndo` `onBeforeExecCommand` `onBeforeGetContent` `onBeforeRenderUI` `onBeforeSetContent` `onBeforePaste` `onBlur` `onChange` `onClearUndos` `onClick` `onContextMenu` `onCopy` `onCut` `onDblclick` `onDeactivate` `onDirty` `onDrag` `onDragDrop` `onDragEnd` `onDragGesture` `onDragOver` `onDrop` `onExecCommand` `onFocus` `onFocusIn` `onFocusOut` `onGetContent` `onHide` `onInit` `onKeyDown` `onKeyPress` `onKeyUp` `onLoadContent` `onMouseDown` `onMouseEnter` `onMouseLeave` `onMouseMove` `onMouseOut` `onMouseOver` `onMouseUp` `onNodeChange` `onObjectResizeStart` `onObjectResized` `onObjectSelected` `onPaste` `onPostProcess` `onPostRender` `onPreProcess` `onProgressState` `onRedo` `onRemove` `onReset` `onSaveContent` `onSelectionChange` `onSetAttrib` `onSetContent` `onShow` `onSubmit` `onUndo` `onVisualAid`



# [Custom Directives]
[Custom Directives]: https://vuejs.org/v2/guide/custom-directive.html

	// Register a global custom directive called `v-focus`
	Vue.directive('focus', {
	  // When the bound element is inserted into the DOM...
	  inserted: function (el) {
	    // Focus the element
	    el.focus()
	  }
	})

If you want to register a directive locally instead, components also accept a directives option:

	directives: {
	  focus: {
	    // directive definition
	    inserted: function (el) {
	      el.focus()
	    }
	  }
	}

Then in a template, you can use the new v-focus attribute on any element, like this:

	<input v-focus>

Hook Functions

A directive definition object can provide several hook functions (all optional):

* `bind()`: called only once, when the directive is first bound to the element. This is where you can do one-time setup work.
* `inserted()`: called when the bound element has been inserted into its parent node (this only guarantees parent node presence, not necessarily in-document).
* `update()`: called after the containing component’s VNode has updated, but possibly before its children have updated. The directive’s value may or may not have changed, but you can skip unnecessary updates by comparing the binding’s current and old values (see below on hook arguments).
* `componentUpdated`: called after the containing component’s VNode and the VNodes of its children have updated.
* `unbind`: called only once, when the directive is unbound from the element.


关于 VNode 参考渲染波函数 [Render Function]。

Function Shorthand

In many cases, you may want the same behavior on bind and update, but don’t care about the other hooks. For example:

	Vue.directive('color-swatch', function (el, binding) {
	  el.style.backgroundColor = binding.value
	})

Object Literals

If your directive needs multiple values, you can also pass in a JavaScript object literal. Remember, directives can take any valid JavaScript expression.

	<div v-demo="{ color: 'white', text: 'hello!' }"></div>
	Vue.directive('demo', function (el, binding) {
	  console.log(binding.value.color) // => "white"
	  console.log(binding.value.text)  // => "hello!"
	})

An example of a custom directive using a dynamic argument:

	<div id="app">
	  <p>Scroll down the page</p>
	  <p v-tack:left="[dynamicleft]">I’ll now be offset from the left instead of the top</p>
	</div>

	Vue.directive('tack', {
	  bind(el, binding, vnode) {
	    el.style.position = 'fixed';
	    const s = (binding.arg == 'left' ? 'left' : 'top');
	    el.style[s] = binding.value + 'px';
	  }
	})

	// start app
	new Vue({
	  el: '#app',
	  data() {
	    return {
	      dynamicleft: 500
	    }
	  }
	})

Directive Hook Arguments

Directive hooks are passed these arguments:

* `el`: The element the directive is bound to. This can be used to directly manipulate the DOM.
* `binding`: An object containing the following properties.
* `name`: The name of the directive, without the v- prefix.
* `value`: The value passed to the directive. For example in v-my-directive="1 + 1", the value would be 2.
* `oldValue`: The previous value, only available in update and componentUpdated. It is available whether or not the value has changed.
* `expression`: The expression of the binding as a string. For example in v-my-directive="1 + 1", the expression would be "1 + 1".
* `arg`: The argument passed to the directive, if any. For example in v-my-directive:foo, the arg would be "foo".
* `modifiers`: An object containing modifiers, if any. For example in v-my-directive.foo.bar, the modifiers object would be { foo: true, bar: true }.
* `vnode`: The virtual node produced by Vue’s compiler. See the VNode API for full details.
* `oldVnode`: The previous virtual node, only available in the update and componentUpdated hooks.

Apart from el, you should treat these arguments as read-only and never modify them. If you need to share information across hooks, it is recommended to do so through element’s dataset.

An example of a custom directive using some of these properties:

	<div id="hook-arguments-example" v-demo:foo.a.b="message"></div>

	Vue.directive('demo', {
	  bind: function (el, binding, vnode) {
	    var s = JSON.stringify
	    el.innerHTML =
	      'name: '       + s(binding.name) + '<br>' +
	      'value: '      + s(binding.value) + '<br>' +
	      'expression: ' + s(binding.expression) + '<br>' +
	      'argument: '   + s(binding.arg) + '<br>' +
	      'modifiers: '  + s(binding.modifiers) + '<br>' +
	      'vnode keys: ' + Object.keys(vnode).join(', ')
	  }
	})

	new Vue({
	  el: '#hook-arguments-example',
	  data: {
	    message: 'hello!'
	  }
	})




# babel 工具使用

IE天生天然残缺，像反引号/模板字符串/ES6对象解构等待支持不到位，如果要vue兼容IE，这些特异功能就不能用了。浏览器的更新速度跟不上脚本发展的速度，使用新脚本特性的需求又强烈，那么Babel就产生了，它可以让你在落后的浏览器使用新的语言特性。

Babel 是一个 JavaScript 语法解析器，Babel is a JavaScript compiler。将 ECMAScript 6 代码转换成浏览器可识别的 ECMAScript 5 代码，这也正是 Babel 的前身 6to5 名字的由来。随着 Babel 不断的发展，现在它已经不再仅仅为了 6to5 而存在。本文旨在跟大家聊一聊如今的 Babel 是怎样处理我们的代码，以及我们还能用 Babel 做些什么。要使用 Babel 的功能，最直接的办法就是引入它的 core-js-bundle：

    <script type="text/javascript" src="//unpkg.com/core-js-bundle@3.0.0-beta.3/minified.js"></script>

由于 Babel 默认只转换转各种 ES2015 语法，而不转换新的 API，比如 Promise，以及 Object.assign、Array.from 这些新方法，这时我们需要提供一些 ployfill 来模拟出这样一个提供原生支持功能的浏览器环境。

主要有两种方式：babel-runtime 和 babel-polyfill。

babel-runtime 的作用是模拟 ES2015 环境，包含各种分散的 polyfill 模块，我们可以在自己的模块里单独引入，比如 promise：

	import 'babel-runtime/core-js/promise'

它们不会在全局环境添加未实现的方法，只是这样手动引用每个 polyfill 会非常低效，我们可以借助 Runtime transform 插件来自动化处理这一切。

而 babel-polyfill 是针对全局环境的，引入它浏览器就好像具备了规范里定义的完整的特性，一旦引入，就会跑一个 babel-polyfill 实例。



+ 以 CLI 方式使用 Babel，安装cli工具，及使用方法：

    npm install --save-dev babel-cli
	babel src -d lib

然后是安装转译器和创建配置文件 .babelrc，只有在配置文件设置了转译器，babel 才对代码进行转换:

	npm install babel-preset-env --save-dev

	// enable babel-preset-env in .babelrc configuration
	{
	  "presets": ["env"]
	}

babel-preset-es2015 这样的配置可以退下了：

	{
	    "presets": [
	        ["es2015", {"modules": false }]
	    ]
	}


babel命令行工具（babel-cli）跟babel转译器(presets暂且用这译法)是两个不同的东西，命令行工具并不具有转译代码的功能，只是为了在命令行中使用babel。要转码必须安装转译器，比如babel-preset-env转译器或者babel-preset-react转译器。要转译的时候，还要在.babelrc文件或者命令行中配置这些转译器(presets)选项。

Babel 的官网宣布 ES2015 / ES2016/ ES2017 等等 ES20xx 时代的 presets 通通被废弃（deprecated），取而代之的是 babel-preset-env，并且承诺它将成为“未来不会过时的（future-proof）”解决方案。

.babelrc不是必须的，我们在.babelrc中配置的选项都可以通过命令行添加，比如在命令行执行 babel src -d lib --presets=env 等价于在.babelrc中配置 "presets":["env"]。当然.babelrc要明显方便很多。

babel在转译代码的过程中会自动读取当前目录.babelrc配置文件，如果当前目录没有的话就遍历整个目录树去寻找，直到找到.babelrc文件或者含有"babel"字段的package.json文件，然后使用这些配置选项来转译代码。

关于.babelrc的注意点如下。

1、如果没有.babelrc文件，或者没有在其他文件中设置过babel的presets的配置选型，并且命令行中也没有配置--presets，那么代码是不会转译的。原es6代码什么样，转译后的代码还是什么样。

2、如果你的.babelrc或者你的命令行使用了你没有安装的转译器（presets），代码就会报错

3、但.babelrc中的配置跟你在命令行中使用的配置冲突的时候，以.babelrc中的配置为准


+ 搭配 webpack 编译系统使用，首先执行安装命令，转译器，一并创建配置文件 .babelrc

	npm install --save-dev babel-loader babel-core
	npm install babel-preset-env --save-dev

如果项目里只有 babel-preset-es2015，那就赶紧装上 babel-preset-env，这个配置不好在IE9上会有 Promise”未定义"。然后通过配置文件方式或 loader 方式使用：

	// Via config
	module: {
		rules: [
			{ test: /\.js$/, exclude: /node_modules/, loader: "babel-loader" }
		]
	}

	// Via loader
	var Person = require("babel!./Person.js").default;
	new Person();

+ 或者使用 babel-polyfill:

	npm install --save-dev babel-polyfill

如果使用vue-cli项目，在webpack.config.js中添加：

	require('babel-polyfill');

	entry: {
	    app: ['babel-polyfill', './src/main.js']
	},


参考文档： 
https://babeljs.io/setup#installation
https://babeljs.io/docs/en/usage
http://www.ruanyifeng.com/blog/2016/01/babel.html


Vue 全家桶是 Vue 和 Vue-router，Vuex，Axios 组合的统称，这四个组合在一起可以算是一个全功能前端开发配置，VueRouter 做SPA单页面应用，Vuex 做数据仓库状态管理，Axios 做 Ajax 应用。

ivew则是基于vue的ui组件库，类似ui组件库还有 elment, mint-ui等。

iview 快速上手： https://www.iviewui.com/docs/guide/start#AXYY

# CSS热更新 双向修改 Chrome DevTools

Chrome 开发都工具提供了一个非常实用有功能，通过映射将页面的样式关联到本地的一个样式表文件，下面是设置步骤

第一步是设置工作区

	+ 打开chrome开发者工具(F12)
	+ 选择 source 栏，在左栏任意位置右键，点击'Add folder to workspace'
	+ 选择一个本地工作目录，里面应该含有 css 样式文件
	+ 在弹出权限提示框中，点击'允许'即可
	+ Sources 栏会新增添加进来的文件夹，则说明工作区配置好了

第二步是设置样式文件映

	+ 在 Sources 栏的目录树中选择你想进行映射的css文件，右键菜单选择'Map to file system resource..
	+ 在弹出框中选择工作区中相应的css文件
	+ 选择完成后可以看到，原先在服务器中的文件被移到了我们的工作区文件夹中

第三步是测试实时更新效果

配置好了工作区和文件映射，来看看最终的效果吧

	+ 我们先修改本地css中的内容，在这里，我们将p标签的颜色属性改为绿色，并保存查看浏览器更新。
	+ 接着我们在Elemnts栏中，手动更改h1标签的font-size属性
	+ 回到工作区的文件中，可以看到文件也被实时更新了，再也不用按F5刷新了！！！


以下几点注意事项摘自chrome开发者工具帮助手册
1、只有 Elements 面板中的样式更改会保留；对 DOM 的更改不会保留
2、仅可以保存在外部 CSS 文件中定义的样式。对 element.style 或内嵌样式的更改不会保留。
3、如果您有映射到本地文件的 CSS 资源，在 Elements面板中进行的样式更改无需显式保存即会立即保留 - Ctrl + S 或者 Cmd + S (Mac)
4、如果您正在从远程服务器映射文件，Chrome 会从远程服务器重新加载页面。您的更改仍将保存到磁盘，并且如果您在工作区中继续编辑，这些更改将被重新应用
5、您必须在浏览器中使用映射文件的完整路径。要查看暂存版本，您的索引文件在网址中必须包含 .html


# 浏览器上使用 Vue Devtools 工具

Vue.js devtools是基于google chrome浏览器的一款调试vue.js应用的开发者浏览器扩展，可以在浏览器开发者工具下调试代码。

可以通过 github 下载devtools源码，用 npm 编译安装，地址：https://github.com/vuejs/vue-devtools。
也可就直接下载编译版本，在任意空目录下执行 npm 获取 devtools 插件：

	npm i vue-devtools

以上命令会下载插件到 node_modules\vue-devtools\vender 目录中，其中 manifest.json 就是 Chrome & Firefox 安装插件时需要用到的配置文件。手上在用的UC也是可以安装的，打开扩展面板，开启开发者模式，就可以装入已解压的插件。



常见问题

+ Vue.js not detected

+ Vue.js is detected on this page. Devtools inspection is not available because it's in production mode or explicitly disabled by the author.
若在浏览器中打开控制台刷新之后还是没有vue，可以检查是否使用的是压缩版本的vue.min.js，默认为生产环境的，这种情况是默认关闭调试的。

	<script src="https://unpkg.com/vue/dist/vue.js"></script>

+ Vue.js is detected on this page. Open DevTools and look for the Vue panel. 
重启浏览器就可以在开发工具面板中找到vue


或者在代码的主文件中配置vue的环境：

	Vue.config.devtools = true

尝试在配置文件plugin中导出:

    new webpack.DefinePlugin({
        'process.env': { 'NODE_ENV':'"development"'}
    }),

可以选择把后台常驻模式打开，persistent 设置为 true

	"background": {
		"scripts": [
		  "build/background.js"
		],
		"persistent": false
	}




# render function & createComponent

[Render Function]: https://vuejs.org/v2/guide/render-function.html
[Render Function 中文文档]: https://cn.vuejs.org/v2/guide/render-function.html

Vue 推荐在绝大多数情况下使用 template 来创建你的 HTML。然而在一些场景中，你真的需要 JavaScript 的完全编程的能力，这就是 [render] 函数，它比 template 更接近编译器。参考官方文档 [Render Function]、 [Render Function 中文文档]。

在 Vue 程序的运行过程中，内部始终以 Virtual DOM 的概念管理组件的模板，渲染函数 [render] 则是将虚拟 DOM 向浏览器的 DOM 转换过程的重要环节。在适当的时候 Vue 会调用渲染函数，并传入一个 createElement 回调方法，它就是用来构建虚拟 DOM 的方法，第一个由 createElement 方法构造出来的对象就是一个虚拟节点 VNode 对象，虚拟 DOM 就是所有虚拟节点的集合。绝大多数情况下使用 template 来创建 HTML，但是要使用 JavaScript 的完全编程的能力，就需要实现自己的 [render] 函数，结合 createElement 函数，可以构造任意结构的 HTML，这就是 [render] 的作用。注意入口程序中的 [render] 函数是 ES6 函数简略语法，理解它需要有 ES6 语法基础，通过对比以下同种等价表达会更清晰。


```javascript
	render: h => h(App); // 项目模板代码写法

	render (h){
	    return h(App);
	}

	render (createElement) {
	    return createElement(App);
	}

	render: function (createElement) {
	    return createElement(App);
	}
```

通过实现自己的渲染函数可以构造出任意的 HTML，但重点还在 createElement 这个函数内，它接收二个参数，第一个是虚拟 DOM 的节点类型，或者是模板对象，也可以是返回这两种数据的回调函数。第二个是可选参数可以是属性数据对象或者是 VNode 数组，VNode 将当作子节点。

```javascript
	return createElement( 'div' );
	return createElement( {template: '<div></div>'} );
	return createElement( ()=>{ return { template: '<div></div>'}; });

	return createElement('div', [createElement('h1', '主标'), createElement('h2', '副标') ]);

	return createElement('div', {
		class: { foo: true,  bar: false },
		style: { color: 'red', fontSize: '14px' },
		attrs: { id: 'foo' },
		domProps: { innerHTML: 'anything'}
	});
```

第二个可选参数作为属性传入时，可以设置的内容很丰富，除基本的 style、class 等属性，还有其它各种内容，如设置组件属性 props，绑定事件 on 或 nativeOn，插槽设置 scopedSlots、slot，设置顶级变量 key、ref，甚至是自定义指令符号 directives。


其中 根据 Vue.js 作者 Even You 的回复，h 的含义如下：

	It comes from the term "hyperscript", which is commonly used in many virtual-dom implementations. "Hyperscript" itself stands for "script that generates HTML structures" because HTML is the acronym for "hyper-text markup language".

下面这个列子展示了 render 函数和 createElemnt 函数结合来动态生成模板，这种使用脚本生成的组件称为函数式组件。

	<div id="app">
	    <child v-bind:level="2">Hello world!</child>
	</div>

	<script type="text/javascript">

	Vue.component('child', {
	    render: function (createElement) {
	        return createElement(
	            'h' + this.level, // tag name 标签名称 h1,h2,h3...
	            this.$slots.default // 子组件中的阵列
	        )
	    },
	    props: {
	        level: {
	            type: Number,
	            required: true
	        }
	    }
	})

	new Vue({
	    el: "#app"
	})

	</script>


## 函数式组件

可以将组件标记为 functional，这意味它无状态，即没有响应式数据，也没有实例，也就没有 `this` 上下文指向组件实例，但可以在渲染函数中多接收一个 `context` 参数。这是一个 FunctionalRenderContext 对象，用它来替代组件实例上下文，其 `parent` 属性指向的就是一个 Vue 组件实例。函数式组件与常规组件的区别还体现在 `createElement()` 创建的根节点上，常规组件的渲染函数中返回的结果是不包含根节点的，但函数式组件的渲染函数返回的根节点会出现在浏览器 DOM 结构上。一个函数式组件骨架就像如下这样：

	Vue.component('my-component', {
		functional: true,
		props: {
			// Props 是可选的 Vue 2.3.0+
		},
		render: function (createElement, context) {
			// ...
		}
	})

在 Vue 2.3.0 之前的版本中，一个函数式组件想要接收 prop，则 props 选项是必须的。之后的版本则可以省略 props 选项，所有组件上的特性都会被自动隐式解析为 prop。当然显式声明 props 是一个好习惯，另外 props 还可以用来接收路由视图组件的参数，如果使用了 Vue Router 提供的 `router-view` 来渲染组件。在 Vue 2.5.0+ 版本中，还可以在单文件组件的模板上声明函数式组件：

	<template functional> ... </template>

函数式组件需要的一切都是通过 context 参数传递，这个上下文对象包含以下属性内容，和 Vue 组件实例的属性相似：

**props** 提供所有 prop 的对象
**children** VNode 子节点的数组
**slots** 一个函数，返回了包含所有插槽的对象
**scopedSlots** (2.6.0+) 一个暴露传入的作用域插槽的对象。也以函数形式暴露普通插槽。
**data** 传递给组件的整个数据对象，作为 createElement 的第二个参数传入组件
**parent** 对父组件的引用
**listeners**  (2.3.0+) 一个包含了所有父组件为当前组件注册的事件监听器的对象。这是 data.on 的一个别名。
**injections**  (2.3.0+) 如果使用了 inject 选项，则该对象包含了应当被注入的属性。

在添加 `functional: true` 之后，原组件的的渲染函数就要增加 context 参数，并将 `this.$slots.default` 更新为 `context.children`，然后将原来通过 `this` 访问的属性改为通过 `context.props` 来访问。

在 Vue 系统内，模板是要编译成渲染函数运行的，无论是运行时编译还是单文件组件方式的预编译，模板最终都会被编译成渲染函数，执行渲染函数生成 Vue 内部的 VNode 节点。所以使用函数式组件相应对使用模板，可以节省运行时的模板编译开销，有助于提升程序运行效率。至于模板编译，还可以手动使用 [Vue.compile( template )] 来实时编译模板字符串。


# [Server-Side Render] SSR 服务端渲染
[Server-Side Render]: https://cn.vuejs.org/v2/guide/ssr.html
[SSR 完全指南]: https://ssr.vuejs.org/zh/
[Nuxt.js]: https://nuxtjs.org/
[Quasar Framework]: https://quasar-framework.org/
[Nightwatch.js]: https://nightwatchjs.org
[Hello World - Nuxt.js]: https://zh.nuxtjs.org/examples
[AVA]: https://github.com/avajs/ava
[Nuxt.js 开发工具]: https://zh.nuxtjs.org/guide/development-tools

SSR 服务端渲染大致的意思就是 Vue 在客户端将标签渲染成的整个 HTML 片段的工作转移到服务端完成，服务端形成的 HTML 片段直接返回给客户端这个过程就叫做服务端渲染。服务端渲染的核心就在于：通过 `vue-server-renderer` 插件的 `renderToString()` 方法，将Vue实例转换为字符串插入到html文件。

+ 浏览器加载所有资源(HTML、CSS、JS、IMG...)
+ 加载 CDN 资源
+ Vue 请求服务器获取业务数据
+ 返回渲染后的 HTML 片段
+ CSS 渲染片段合成一个网页

这里面最耗时的请求服务器并返回渲染 HTML 片段这两步骤，请求服务器 API 的过程本身除了服务器的限制，还有用户网络，宽带等等诸多限制，并且当页面逻辑过多，数据过于繁琐的情况下，Vue 在客户端渲染也会成为性能瓶颈，如一些电商公司的首页，商品详情页等等。如果页面呈现时间需要 200ms 以上，这个时间几乎是难以接受的，在用户网络不是很好的情况下，这个过程甚至需要 500ms 以上的时间，再加上其他的各种请求资源，手机性能等等，用户就要看到将近一秒的白屏时间，这个明显是很差的用户体验。

在对你的应用程序使用服务器端渲染(SSR)之前，你应该问的第一个问题是，是否真的需要它。这主要取决于内容到达时间(time-to-content)对应用程序的重要程度。例如，如果你正在构建一个内部仪表盘，初始加载时的额外几百毫秒并不重要，这种情况下去使用服务器端渲染(SSR)将是一个小题大作之举。然而，内容到达时间(time-to-content)要求是绝对关键的指标，在这种情况下，服务器端渲染(SSR)可以帮助你实现最佳的初始加载性能。

Vue 2.3 后发布一份完整的构建 Vue 服务端渲染应用的指南，这份指南非常深入，适合已经熟悉 Vue, webpack 和 Node.js 开发的开发者阅读，戳这 [SSR 完全指南]。

## SSR 指南

先通过 NPM 或 YARN (Yet Another Resource Negotiator) 安装 Vue SSR 模块：

	npm install vue vue-server-renderer --save

注意要求 Node.js 6+ 版本，并且 `vue-server-renderer` 和 Vue 版本必须匹配。目前  `vue-server-renderer` 依赖一些 Node.js 原生模块，因此只能在 Node.js 中使用。

### 渲染一个 Vue 实例

	// 第 1 步：创建一个 Vue 实例
	const Vue = require('vue')
	const app = new Vue({
	  template: `<div>Hello World</div>`
	})

	// 第 2 步：创建一个 renderer
	const renderer = require('vue-server-renderer').createRenderer()

	// 第 3 步：将 Vue 实例渲染为 HTML
	renderer.renderToString(app, (err, html) => {
	  if (err) throw err
	  console.log(html)
	  // => <div data-server-rendered="true">Hello World</div>
	})

	// 在 2.5.0+，如果没有传入回调函数，则会返回 Promise：
	renderer.renderToString(app).then(html => {
	  console.log(html)
	}).catch(err => {
	  console.error(err)
	})

### 与服务器集成

在 Node.js 服务器中使用时相当简单直接，例如 Express：

	npm install express --save
	const Vue = require('vue')
	const server = require('express')()
	const renderer = require('vue-server-renderer').createRenderer()

	server.get('*', (req, res) => {
	  const app = new Vue({
	    data: {
	      url: req.url
	    },
	    template: `<div>访问的 URL 是： {{ url }}</div>`
	  })

	  renderer.renderToString(app, (err, html) => {
	    if (err) {
	      res.status(500).end('Internal Server Error')
	      return
	    }
	    res.end(`
	      <!DOCTYPE html>
	      <html lang="en">
	        <head><title>Hello</title></head>
	        <body>${html}</body>
	      </html>
	    `)
	  })
	})

	server.listen(8080)

### 使用一个页面模板

当你在渲染 Vue 应用程序时，renderer 只从应用程序生成 HTML 标记 (markup)。在这个示例中，我们必须用一个额外的 HTML 页面包裹容器，来包裹生成的 HTML 标记。

为了简化这些，你可以直接在创建 renderer 时提供一个页面模板。多数时候，我们会将页面模板放在特有的文件中，例如 index.template.html：

	<!DOCTYPE html>
	<html lang="en">
	  <head><title>Hello</title></head>
	  <body>
	    <!--vue-ssr-outlet-->
	  </body>
	</html>
	注意 <!--vue-ssr-outlet--> 注释 -- 这里将是应用程序 HTML 标记注入的地方。

	然后，我们可以读取和传输文件到 Vue renderer 中：

	const renderer = createRenderer({
	  template: require('fs').readFileSync('./index.template.html', 'utf-8')
	})

	renderer.renderToString(app, (err, html) => {
	  console.log(html) // html 将是注入应用程序内容的完整页面
	})

### 模板插值

模板还支持简单插值。给定如下模板：

	<html>
	  <head>
	    <!-- 使用双花括号(double-mustache)进行 HTML 转义插值(HTML-escaped interpolation) -->
	    <title>{{ title }}</title>

	    <!-- 使用三花括号(triple-mustache)进行 HTML 不转义插值(non-HTML-escaped interpolation) -->
	    {{{ meta }}}
	  </head>
	  <body>
	    <!--vue-ssr-outlet-->
	  </body>
	</html>

我们可以通过传入一个"渲染上下文对象"，作为 renderToString 函数的第二个参数，来提供插值数据：

	const context = {
	  title: 'hello',
	  meta: `
	    <meta ...>
	    <meta ...>
	  `
	}

	renderer.renderToString(app, context, (err, html) => {
	  // 页面 title 将会是 "Hello"
	  // meta 标签也会注入
	})

也可以与 Vue 应用程序实例共享 context 对象，允许模板插值中的组件动态地注册数据。

此外，模板支持一些高级特性，例如：

* 在使用 `*.vue` 组件时，自动注入「关键的 CSS(critical CSS)」；
* 在使用 clientManifest 时，自动注入「资源链接(asset links)和资源预加载提示(resource hints)」；
* 在嵌入 Vuex 状态进行客户端融合(client-side hydration)时，自动注入以及 XSS 防御。


## SSR 第三方框架

[Quasar Framework] 可以通过其一流的构建系统、合理的配置和开发者扩展性生成 SSR 应用，让你的想法的设计和构建变得轻而易举。 还可以可选地和 PWA(Progressive Web App) 互通的。你可以在服务端挑选执行超过上百款遵循“Material Design 2.0”的组件，并在浏览器端可用。你甚至可以管理网站的 `<meta>` 标签。Quasar 是一个基于 Node.js 和 webpack 的开发环境，它可以通过一套代码完成 SPA、PWA、SSR、Electron 和 Cordova 应用的快速开发。

Vue 有一个优秀的社区项目 [Nuxt.js]，可以让搭建服务端渲染的工作变得非常简单。它是一个基于 Vue 生态的更高层的框架，为开发服务端渲染的 Vue 应用提供了极其便利的开发体验。更酷的是，你甚至可以用它来做为静态站生成器，支持 Vue.js 应用的静态化算是 Nuxt.js 的一个创新点，通过 `nuxt generate` 命令即可将 Vue 项目编译得到一个静态化站点。[Nuxt.js] 集成了以下组件或框架，gzip 压缩后总代码大小为 57kb，使用了 Vuex 特性为 60kb：

* Vue 2
* Vue-Router
* Vuex (当配置了 Vuex 状态树配置项 时才会引入)
* Vue 服务器端渲染 (排除使用 mode: 'spa')
* Vue-Meta

另外，[Nuxt.js] 使用 `Webpack` 和 `vue-loader`、 `babel-loader` 进行自动化构建工作，如打包、代码分层、压缩等等。

Nuxt.js 提供了一系列常用的命令, 用于开发或发布部署，还有相应的命令参数如下：

|命令	|描述	|
|-------|-------|
|nuxt	|启动一个热加载的Web服务器（开发模式） localhost:3000。|
|nuxt build	|利用webpack编译应用，压缩JS和CSS资源（发布用）。|
|nuxt start	|以生产模式启动一个Web服务器 (nuxt build 会先被执行)。|
|nuxt generate	|编译应用，并依据路由配置生成对应的HTML文件 (用于静态站点的部署)。|

* `--help`: 命令来获取详细用法。
* `-c`、`--config-file`: 指定 nuxt.config.js 的文件路径。
* `-s`、`--spa`: 禁用服务器端渲染，使用SPA模式
* `-n`、`--unix-socket`: 指定UNIX Socket的路径。

如果使用了 Koa/Express 等 Node.js Web 开发框架，并使用了 Nuxt 作为中间件，可以自定义 Web 服务器的启动入口：

|命令	|描述	|
|-------|-------|
|NODE_ENV=development nodemon server/index.js	|启动一个热加载的自定义 Web 服务器（开发模式）。|
|NODE_ENV=production node server/index.js	|以生产模式启动一个自定义 Web 服务器 (需要先执行 nuxt build)。|


来看看官网提供的一个 [Hello World - Nuxt.js] 示例，其中配置文件 `nuxt.config.js` 没有内容，使用默认配置项：

	// nuxt.config.js
	
	// readme.md
	# Hello World with Nuxt.js
	https://nuxtjs.org/examples	

	// package.json
	{
	  "name": "example-hello-world",
	  "dependencies": {
	    "nuxt": "latest"
	  },
	  "scripts": {
	    "dev": "nuxt",
	    "build": "nuxt build",
	    "start": "nuxt start",
	    "post-update": "yarn upgrade --latest"
	  }
	}

	// above.vue
	<template>
	  <div>
	    <p>Hi from {{ name }}</p>
	    <NLink to="/">
	      Home page
	    </NLink>
	  </div>
	</template>

	<script>
	export default {
	  asyncData() {
	    return {
	      name: process.static ? 'static' : (process.server ? 'server' : 'client')
	    }
	  },
	  head: {
	    title: 'About page'
	  }
	}
	</script>

	// index.vue
	<template>
	  <div>
	    <h1>Welcome!</h1>
	    <NLink to="/about">
	      About Page
	    </NLink>
	  </div>
	</template>

	<script>
	export default {
	  head: {
	    title: 'Home page'
	  }
	}
	</script>

编写好程序后，也许还需要一套测试工具来做一些功能测试，[AVA] 是一个很强大的 JavaScript 测试框架，结合 jsdom，我们就可以轻松地给 nuxt 应用进行端对端测试，参考 [Nuxt.js 开发工具]。如果需要使用真实的浏览器引擎来测试，可以考虑 [Nightwatch.js]。




# props 向组件传递参数

组件属性 prop 定义的方式有两种，一种是简易的形式，使用数组来定义属性名列表即可：

	props: ['options', 'moreOptions']

另一种是完整的定义，包括指定数据类型，指定默认值，`validator` 自定义验证函数等功能：

	props: {
	    propA: Number, // 基础类型检测 （`null` 意思是任何类型都可以）
	    propB: [String, Number],					// 多种类型
	    propC: { type: String, required: true },	// 必传且是字符串
	    propD: { type: Number, default: 100 },		// 数字，有默认值
	    propE: { type: Object, default: function () { return { message: 'hello' } } },
	    propF: { validator: function (value) { return value > 10 }
	}


	<div id="components-app">
		<div :style="{color:color}">{{state}}</div>
		<button-counter v-on:reset="doReset" v-for="item in list" v:bind:title="{{item}}"></button-counter>
	</div>

	<script>
		Vue.component('button-counter', {
			props:['title'],
			data: function () {
				return {
					count: 0
				}
			},
			template: '<button v-on:click="count++; if(count==9) $emit(\'reset\')">You clicked {{title}} {{ count }} times.</button>'
		});

		new Vue({ 
			el: '#components-app',
			data:{
				list:['Apple','Pie','Cake'],
				color:'black',
				state:"working"
			},
			methods:{
				doReset:function(res){
					this.color = 'red';
					this.state = "Reset";
				}
			}
		});
	</script>

# refs 引用及组件成员访问 组件嵌套 template组件模板引用
https://www.w3cplus.com/vue/seven-ways-to-define-a-component-template-by-vuejs.html

Vue.js 中可以用7种定义组件模板的方法, inline-template:

	Vue.component('my-checkbox', {
	    data() {
	        return {
	            checked: false,
	            title: 'Check me'
	        }
	    },
	    methods: {
	        check() {
	            this.checked = !this.checked;
	        }
	    }
	});
	
	<my-checkbox inline-template>
	    <div class="checkbox-wrapper" @click="check">
	        <div :class="{ checkbox: true, checked: checked }"></div>
	        <div class="title"></div>
	    </div>
	</my-checkbox>

单文件组件
只要你把构建工具设置的很舒服，单文件组件就是模板选项中的王者。它允许你写 HTML 标签定义组件，并且将所有组件定义保留在一个文件中。

尽管它也有一些劣势：需要预编译，某些 IDE 不支持 .vue 文件的语法高亮，不过其地位依然难以被撼动。

	<template>
	    <div class="checkbox-wrapper" @click="check">
	        <div :class="{ checkbox: true, checked: checked }"></div>
	        <div class="title"></div>
	    </div>
	</template>
	<script>
	    export default {
	        data() {
	            return {
	                checked: false,
	                title: 'Check me'
	            }
	        },
	        methods: {
	            check() {
	                this.checked = !this.checked;
	            }
	        }
	    }
	</script>

x-template:

	<script type="text/x-template" id="checkbox-template">
		<div class="checkbox-wrapper" @click="check">
			<div :class="{ checkbox: true, checked: checked }"></div>
			<div class="title"></div>
		</div>
	</script>



其中模板字符串（Template literals）

通过ES6的模板字符串（反引号 ` ` ）语法，你在定义模板时可以直接换行，这是通过常规的JavaScript字符串没法做到的。这种写法更容易阅读，并且这种模板字符串语法得到了许多新版本浏览器的支持。当然，为了安全起见，你仍然应该把它转译为ES5的语法形式。

然而，这种方式并不完美，我发现大多数的IDE在语法高亮上做的差强人意，并且在缩进和换行等的格式方面，仍然很痛苦。


	<div id="template-app">
		<i-button @click="doReset">Reset</i-button>
		<button-counter ref="demoButton" title="Apple"></button-counter>
	</div>
	
	<template id="templateDemo">
		<i-button v-on:click="count++;">You clicked {{title}} {{ count }} times.</i-button>
	</template>

	<script>
		Vue.component('button-counter', {
			props:['title'],
			data: function () {
				return {
					count: 0
				}
			},
			methods:{
				reset:function(res){
					this.count = 0;
					console.log(this);
				}
			},
			template: '#templateDemo'
		});

		new Vue({ 
			el: '#template-app',
			methods:{
				doReset:function(){
					console.log(this.$refs);
					this.$refs.demoButton.reset("this call");
				}
			}
		});
	</script>


# iview UI 组件库
https://www.iviewui.com/docs/introduce

## 升级 4.x 指南

该项目即为原先的 iView，从 2019 年 10 月起正式更名为 View UI，并使用全新的 Logo 。iView 作者将在新仓库（https://github.com/view-design/ViewUI）继续开发 iView 4.0 和后续版本，以及维护工作。原仓库 iView 作者不再继续提交内容。
View UI（iView）从 4.0.0 版本开始，需将 npm 包 iview 替换为 view-design。

需要将 npm 包 iview 以及任何引用 iview 的地方都替换为 view-design，一般来说，有以下几处：

	package.json 中，添加新包 view-design：

	"dependencies": {
	    "view-design": "^4.0.0"
	}

添加完后需要执行 npm install，或者直接通过 npm install view-design --save 安装新包。

Webpack 入口 main.js 中，把原先引用的 iview 替换为 view-design：

	import Vue from 'vue';
	import ViewUI from 'view-design';

	// import style
	import 'view-design/dist/styles/iview.css';

	Vue.use(ViewUI);

同理，如果是按需引用，任何使用 from 'iview' 的都要替换为 from 'view-design'。

如果您在项目中使用了 iview 内置的工具函数文件，比如 iview/src/utils/assist.js 等，都要进行包名替换来使用最新版本，如未使用，请忽略：

	// e.g.
	import { findComponentDownload } from 'view-design/src/utils/assist';

	import { on, off } from 'view-design/src/utils/dom';




## iview CDN 引入

CDN引入方式简单，直接在页面添加CSS和JS标签即可，不像NODE构建环境需要下载大量依赖

	<script src="https://cdn.bootcss.com/vue-resource/1.5.1/vue-resource.min.js"></script>
	<script type="text/javascript" src="http://vuejs.org/js/vue.min.js"></script>
	<link rel="stylesheet" type="text/css" href="http://unpkg.com/iview/dist/styles/iview.css">
	<script type="text/javascript" src="http://unpkg.com/iview/dist/iview.min.js"></script>

	<div id="tabapp">
	    <Tabs value="name1">
	        <Tab-pane label="标签一" name="name1">标签一的内容</Tab-pane>
	        <Tab-pane label="标签二" name="name2">标签二的内容</Tab-pane>
	        <Tab-pane label="标签三" name="name3">标签三的内容</Tab-pane>
	    </Tabs>
	</div>

	<script>
	new Vue({
	    el: '#tabapp',
	})
	</script>

注意：非 template/render 模式下，组件名字可能需作修改，比如vue文件中的Button，在HTML页面中要使用 i-button。 再如VUE中HTML标签名不分大小，像 TabPane 这种组件名要修改成 Tab-Pane。再有，组件属性中使用了连字符，即减号的在脚本中要转成驼峰写法。

以下组件，在非 template/render 模式下，需要加前缀 i-：

Button: i-button 
Col: i-col 
Table: i-table 
Input: i-input 
Form: i-form 
Menu: i-menu 
Select: i-select 
Option: i-option 
Progress: i-progress 
以下组件，在所有模式下，必须加前缀 i-，除非使用 iview-loader： 
Switch: i-switch 
Circle: i-circle 


## iview NODE 构建方式

NODE方式复杂，设计NODE，需要这方面的项目基础。但这种方式可以使用vue文件编写程序，可以借助webpack对代码打包，具有一定的反抄袭功能。使用 iview-project 脚手架工具帮助建项目，然后执行对应命令安装依赖/进入开发/编译：

iview/iview-project: https://github.com/iview/iview-project

	npm install
	npm run dev
	npm run build	

手工建立 iview 项目步骤：

（1）在git bash中安装iview，即：

	npm install iview --save

（2）一般在 webpack 入口页面 main.js 中如下配置并注册iView，即：

	import iView from 'iview'
	import 'iview/dist/styles/iview.css'

	Vue.use(iView)

（3）为了统一IView标签的书写规范，通过安装iView Loader，即：

	npm install iview-loader --save

然后修改webpack选项，如下：

	rules: [
	   ...(config.dev.useEslint ? [createLintingRule()] : []),
	   {
	     test: /\.vue$/,
	     use: [
	       {
	         loader: 'vue-loader',
	         options: vueLoaderConfig
	       },
	       {
	         loader: 'iview-loader',
	         options: {
	             prefix: false
	         }
	       }
	     ]
	     
	   },
	   {
	     test: /\.js$/,
	     loader: 'babel-loader',
	     include: [resolve('src'), resolve('test'), resolve('node_modules/webpack-dev-server/client')]
	}


	<template>
	    <Tabs type="card" closable @on-tab-remove="handleTabRemove">
	        <TabPane label="标签一" v-if="tab0">标签一的内容</TabPane>
	        <TabPane label="标签二" v-if="tab1" disabled>标签二的内容</TabPane>
	        <TabPane label="标签三" v-if="tab2">标签三的内容</TabPane>
	    </Tabs>
	</template>
	<script>
	    export default {
	        data () {
	            return {
	                tab0: true,
	                tab1: true,
	                tab2: true
	            }
	        },
	        methods: {
	            handleTabRemove (name) {
	                this['tab' + name] = false;
	            }
	        }
	    }
	</script>


## iview 使用要点

modal 组件中，只能用v-model，value去控制modal组件的开关。用v-if，v-show无效。

	<Modal
	    v-model="modal1"
	    title="普通的Modal对话框标题"
	    @on-ok="ok"
	    @on-cancel="cancel">
	    <p>对话框内容</p>
	    <p>对话框内容</p>
	    <p>对话框内容</p>
	</Modal>

modal 组件中，使用v-model与value的区别。v-model，可以双向数据绑定，如下这样写 无论是点击确定，取消，还是X，都可以正常再次打开。

	<template>
	<Modal
	    v-model="modal1"
	    title="普通的Modal对话框标题"
	 >
	    <p>对话框内容</p>
	    <p>对话框内容</p>
	    <p>对话框内容</p>
	</Modal>
	<Button type="primary" @click="modal1 = true">显示对话框</Button>
	</template>
	<script>
	export default {
	    data () {
	        return {
	            modal1: false
	        }
	    }
	}
	</script>

而使用 value 时，点击确定，取消，还是X，是无法接受到关闭的时model1变为false，所以model1仍为true，所以无法再次打开，除非自己写on-ok和on-cancel方法，手动将model1改成false。

	<template>

	<Modal
	    v-model="modal1"
	    title="普通的Modal对话框标题"
	    @on-ok="modal1 = false"
	    @on-cancel="modal1 = false">
	    <p>对话框内容</p>
	    <p>对话框内容</p>
	    <p>对话框内容</p>
	</Modal>
	<Button type="primary" @click="modal1 = true">显示对话框</Button>
	</template>
	<script>
	export default {
	    data () {
	        return {
	            modal1: false
	        }
	    }
	}
	</script>

v-model 里面如果使用computed的值的话，双向数据绑定时效。vue会报错 。但是可以用computed中的get set解决。

	computed: {
	  getAddress: {
	    get: function () {
	      if(this.$store.state.updateAddress){
	        this.address = this.$store.state.updateAddress
	      }
	      return this.address
	    },
	    set: function (value) {
	      this.address = value
	    },
	  },
	}


Table导出csv嵌套对象

	handleStr(str){
	  let handleStr=str.replace(/[\r\n]/g,""); 
	    //先判断字符里是否含有逗号
	  if(str.indexOf(",") != -1){
	    //如果还有双引号，先将双引号转义，避免两边加了双引号后转义错误              
	    if(str.indexOf("\"") != -1){
	      // 这里必须对全局进行替换，网上原版是没有的，不加全部只能处理数组，不能处理json
	      handleStr=str.replace(/\"/g, "\"\"");
	    }
	    //将逗号转义  
	    handleStr="\""+handleStr+"\"";  
	    return handleStr
	  } 
	  return "\""+handleStr+"\"";  
	}

Table中添加图片

	column：[
	  {
	    title: "头像",
	    width: 160,
	    render: (h, params) => {
	        return h('img', {
	          style: {
	            width: "100px",
	          },
	          // 可以使用domProps或者attrs
	          domProps: {
	            src: params.row.url
	          }
	          // attrs: {
	          //  src: params.row.url  
	          // }
	        })
	    }
	  }
	]

Table中Input等元素操作修改data值

	<Table :columns="column" :data="data"/>

	column：[
	  {
	    title: "标签",
	    width: 160,
	    render: (h, params) => {
	      return h("Input", {
	        props: {
	          value: params.row.label
	        },
	        on: {
	          "on-blur": event => {
	            this.data[params.row.index].label = params.row.label =
	              event.target.value;
	          }
	        }
	      });
	    }
	  }
	]

Form表单对数字、数组校验

	{type: 'number', message: '请输入数字', trigger: 'blur'}
	{type: 'array', message: '请选择', trigger: 'blur'}



# Vue 1.0 API Reference 参考文档目录

## Global Config 
    
### [`debug`] v1
[`debug`](https://v1.vuejs.org/api/#debug)

### [`delimiters`] v1
[`delimiters`](https://v1.vuejs.org/api/#delimiters)

### [`unsafeDelimiters`] v1
[`unsafeDelimiters`](https://v1.vuejs.org/api/#unsafeDelimiters)

### [`silent`] v1
[`silent`](https://v1.vuejs.org/api/#silent)

### [`async`] v1
[`async`](https://v1.vuejs.org/api/#async)

### [`devtools`] v1
[`devtools`](https://v1.vuejs.org/api/#devtools)

    
## Global API 
    
### [`Vue.extend( options )`] v1
[`Vue.extend( options )`](https://v1.vuejs.org/api/#Vue-extend)

### [`Vue.nextTick( callback )`] v1
[`Vue.nextTick( callback )`](https://v1.vuejs.org/api/#Vue-nextTick)

Defer the callback to be executed after the next DOM update cycle. Use it immediately after you’ve changed some data to wait for the DOM update.

	// modify data
	vm.msg = 'Hello'
	// DOM not updated yet
	Vue.nextTick(function () {
	  // DOM updated
	})

### [`Vue.set( object, key, value )`] v1
[`Vue.set( object, key, value )`](https://v1.vuejs.org/api/#Vue-set)

### [`Vue.delete( object, key )`] v1
[`Vue.delete( object, key )`](https://v1.vuejs.org/api/#Vue-delete)

### [`Vue.directive( id, [definition] )`] v1
[`Vue.directive( id, [definition] )`](https://v1.vuejs.org/api/#Vue-directive)

### [`Vue.elementDirective( id, [definition] )`] v1
[`Vue.elementDirective( id, [definition] )`](https://v1.vuejs.org/api/#Vue-elementDirective)

### [`Vue.filter( id, [definition] )`] v1
[`Vue.filter( id, [definition] )`](https://v1.vuejs.org/api/#Vue-filter)

### [`Vue.component( id, [definition] )`] v1
[`Vue.component( id, [definition] )`](https://v1.vuejs.org/api/#Vue-component)

### [`Vue.transition( id, [hooks] )`] v1
[`Vue.transition( id, [hooks] )`](https://v1.vuejs.org/api/#Vue-transition)

### [`Vue.partial( id, [partial] )`] v1
[`Vue.partial( id, [partial] )`](https://v1.vuejs.org/api/#Vue-partial)

### [`Vue.use( plugin, [options] )`] v1
[`Vue.use( plugin, [options] )`](https://v1.vuejs.org/api/#Vue-use)

### [`Vue.mixin( mixin )`] v1
[`Vue.mixin( mixin )`](https://v1.vuejs.org/api/#Vue-mixin)

    
## Data 
    
### [`data`] v1
[`data`](https://v1.vuejs.org/api/#data)

### [`props`] v1
[`props`](https://v1.vuejs.org/api/#props)

### [`propsData`] v1
[`propsData`](https://v1.vuejs.org/api/#propsData)

### [`computed`] v1
[`computed`](https://v1.vuejs.org/api/#computed)

### [`methods`] v1
[`methods`](https://v1.vuejs.org/api/#methods)

### [`watch`] v1
[`watch`](https://v1.vuejs.org/api/#watch)

    
## DOM 
    
### [`el`] v1
[`el`](https://v1.vuejs.org/api/#el)

### [`template`] v1
[`template`](https://v1.vuejs.org/api/#template)

### [`replace`] v1
[`replace`](https://v1.vuejs.org/api/#replace)

    
## Options / Lifecycle Hooks 
    
参考[生命周期图](https://v1.vuejs.org/guide/instance.html#Lifecycle-Diagram)

### [`init`] v1
[`init`](https://v1.vuejs.org/api/#init)

### [`created`] v1
[`created`](https://v1.vuejs.org/api/#created)

### [`beforeCompile`] v1
[`beforeCompile`](https://v1.vuejs.org/api/#beforeCompile)

### [`compiled`] v1
[`compiled`](https://v1.vuejs.org/api/#compiled)

### [`activate`] v1
[`activate`](https://v1.vuejs.org/api/#activate)

### [`ready`] v1
[`ready`](https://v1.vuejs.org/api/#ready)

### [`attached`] v1
[`attached`](https://v1.vuejs.org/api/#attached)

### [`detached`] v1
[`detached`](https://v1.vuejs.org/api/#detached)

### [`beforeDestroy`] v1
[`beforeDestroy`](https://v1.vuejs.org/api/#beforeDestroy)

### [`destroyed`] v1
[`destroyed`](https://v1.vuejs.org/api/#destroyed)

    
## Assets 
    
### [`directives`] v1
[`directives`](https://v1.vuejs.org/api/#directives)

### [`elementDirectives`] v1
[`elementDirectives`](https://v1.vuejs.org/api/#elementDirectives)

### [`filters`] v1
[`filters`](https://v1.vuejs.org/api/#filters)

### [`components`] v1
[`components`](https://v1.vuejs.org/api/#components)

### [`transitions`] v1
[`transitions`](https://v1.vuejs.org/api/#transitions)

### [`partials`] v1
[`partials`](https://v1.vuejs.org/api/#partials)

    
## Misc 
    
### [`parent`] v1
[`parent`](https://v1.vuejs.org/api/#parent)

### [`events`] v1
[`events`](https://v1.vuejs.org/api/#events)

### [`mixins`] v1
[`mixins`](https://v1.vuejs.org/api/#mixins)

### [`name`] v1
[`name`](https://v1.vuejs.org/api/#name)

### [`extends`] v1
[`extends`](https://v1.vuejs.org/api/#extends)

    
## Instance Properties 
    
### [`vm.$data`] v1
[`vm.$data`](https://v1.vuejs.org/api/#vm-data)

### [`vm.$el`] v1
[`vm.$el`](https://v1.vuejs.org/api/#vm-el)

### [`vm.$options`] v1
[`vm.$options`](https://v1.vuejs.org/api/#vm-options)

### [`vm.$parent`] v1
[`vm.$parent`](https://v1.vuejs.org/api/#vm-parent)

### [`vm.$root`] v1
[`vm.$root`](https://v1.vuejs.org/api/#vm-root)

### [`vm.$children`] v1
[`vm.$children`](https://v1.vuejs.org/api/#vm-children)

### [`vm.$refs`] v1
[`vm.$refs`](https://v1.vuejs.org/api/#vm-refs)

### [`vm.$els`] v1
[`vm.$els`](https://v1.vuejs.org/api/#vm-els)

    
## Data 
    
### [`vm.$watch( expOrFn, callback, [options] )`] v1
[`vm.$watch( expOrFn, callback, [options] )`](https://v1.vuejs.org/api/#vm-watch)

### [`vm.$get( expression )`] v1
[`vm.$get( expression )`](https://v1.vuejs.org/api/#vm-get)

### [`vm.$set( keypath, value )`] v1
[`vm.$set( keypath, value )`](https://v1.vuejs.org/api/#vm-set)

### [`vm.$delete( key )`] v1
[`vm.$delete( key )`](https://v1.vuejs.org/api/#vm-delete)

### [`vm.$eval( expression )`] v1
[`vm.$eval( expression )`](https://v1.vuejs.org/api/#vm-eval)

### [`vm.$interpolate( templateString )`] v1
[`vm.$interpolate( templateString )`](https://v1.vuejs.org/api/#vm-interpolate)

### [`vm.$log( [keypath] )`] v1
[`vm.$log( [keypath] )`](https://v1.vuejs.org/api/#vm-log)

    
## Events 
    
### [`vm.$on( event, callback )`] v1
[`vm.$on( event, callback )`](https://v1.vuejs.org/api/#vm-on)

### [`vm.$once( event, callback )`] v1
[`vm.$once( event, callback )`](https://v1.vuejs.org/api/#vm-once)

### [`vm.$off( [event, callback] )`] v1
[`vm.$off( [event, callback] )`](https://v1.vuejs.org/api/#vm-off)

### [`vm.$emit( event, […args] )`] v1
[`vm.$emit( event, […args] )`](https://v1.vuejs.org/api/#vm-emit)

### [`vm.$dispatch( event, […args] )`] v1
[`vm.$dispatch( event, […args] )`](https://v1.vuejs.org/api/#vm-dispatch)

### [`vm.$broadcast( event, […args] )`] v1
[`vm.$broadcast( event, […args] )`](https://v1.vuejs.org/api/#vm-broadcast)

    
## DOM 
    
### [`vm.$appendTo( elementOrSelector, [callback] )`] v1
[`vm.$appendTo( elementOrSelector, [callback] )`](https://v1.vuejs.org/api/#vm-appendTo)

### [`vm.$before( elementOrSelector, [callback] )`] v1
[`vm.$before( elementOrSelector, [callback] )`](https://v1.vuejs.org/api/#vm-before)

### [`vm.$after( elementOrSelector, [callback] )`] v1
[`vm.$after( elementOrSelector, [callback] )`](https://v1.vuejs.org/api/#vm-after)

### [`vm.$remove( [callback] )`] v1
[`vm.$remove( [callback] )`](https://v1.vuejs.org/api/#vm-remove)

### [`vm.$nextTick( callback )`] v1
[`vm.$nextTick( callback )`](https://v1.vuejs.org/api/#vm-nextTick)

同 `Vue.nextTick( callback )`
    
## Lifecycle 
    
### [`vm.$mount( [elementOrSelector] )`] v1
[`vm.$mount( [elementOrSelector] )`](https://v1.vuejs.org/api/#vm-mount)

### [`vm.$destroy( [remove] )`] v1
[`vm.$destroy( [remove] )`](https://v1.vuejs.org/api/#vm-destroy)

Completely destroy a vm. Clean up its connections with other existing vms, unbind all its directives, turn off all event listeners and, if the remove argument is true, remove its associated DOM element or fragment from the DOM.

触发 `beforeDestroy`、 `destroyed` 两个生命周期函数。通过不必执行这个方法，只需使用数据响应式 `v-if`、`v-for` 就可以做到。

参考[生命周期图](https://v1.vuejs.org/guide/instance.html#Lifecycle-Diagram)

    
## Directives 
    
### [`v-text`] v1
[`v-text`](https://v1.vuejs.org/api/#v-text)

### [`v-html`] v1
[`v-html`](https://v1.vuejs.org/api/#v-html)

### [`v-if`] v1
[`v-if`](https://v1.vuejs.org/api/#v-if)

### [`v-show`] v1
[`v-show`](https://v1.vuejs.org/api/#v-show)

### [`v-else`] v1
[`v-else`](https://v1.vuejs.org/api/#v-else)

### [`v-for`] v1
[`v-for`](https://v1.vuejs.org/api/#v-for)

### [`v-on`] v1
[`v-on`](https://v1.vuejs.org/api/#v-on)

### [`v-bind`] v1
[`v-bind`](https://v1.vuejs.org/api/#v-bind)

### [`v-model`] v1
[`v-model`](https://v1.vuejs.org/api/#v-model)

### [`v-ref`] v1
[`v-ref`](https://v1.vuejs.org/api/#v-ref)

### [`v-el`] v1
[`v-el`](https://v1.vuejs.org/api/#v-el)

### [`v-pre`] v1
[`v-pre`](https://v1.vuejs.org/api/#v-pre)

### [`v-cloak`] v1
[`v-cloak`](https://v1.vuejs.org/api/#v-cloak)

    
## Special Elements 
    
### [`component`] v1
[`component`](https://v1.vuejs.org/api/#component)

### [`slot`] v1
[`slot`](https://v1.vuejs.org/api/#slot)

### [`partial`] v1
[`partial`](https://v1.vuejs.org/api/#partial)

    
## Filters 
    
### [`capitalize`] v1
[`capitalize`](https://v1.vuejs.org/api/#capitalize)

### [`uppercase`] v1
[`uppercase`](https://v1.vuejs.org/api/#uppercase)

### [`lowercase`] v1
[`lowercase`](https://v1.vuejs.org/api/#lowercase)

### [`currency`] v1
[`currency`](https://v1.vuejs.org/api/#currency)

### [`pluralize`] v1
[`pluralize`](https://v1.vuejs.org/api/#pluralize)

### [`json`] v1
[`json`](https://v1.vuejs.org/api/#json)

### [`debounce`] v1
[`debounce`](https://v1.vuejs.org/api/#debounce)

### [`limitBy`] v1
[`limitBy`](https://v1.vuejs.org/api/#limitBy)

### [`filterBy`] v1
[`filterBy`](https://v1.vuejs.org/api/#filterBy)

### [`orderBy`] v1
[`orderBy`](https://v1.vuejs.org/api/#orderBy)

    
## Methods 
    
### [`array.$set(index, value)`] v1
[`array.$set(index, value)`](https://v1.vuejs.org/api/#array-set-index-value)

### [`array.$remove(reference)`] v1
[`array.$remove(reference)`](https://v1.vuejs.org/api/#array-remove-reference)

    

# Vue 2.0 API Reference 参考文档目录

## Global Config
    
### `silent` v2
[`silent`][silent]
[silent]: https://vuejs.org/v2/api/#silent

### `optionMergeStrategies` v2
[`optionMergeStrategies`][optionMergeStrategies]
[optionMergeStrategies]: https://vuejs.org/v2/api/#optionMergeStrategies

### `devtools` v2
[`devtools`][devtools]
[devtools]: https://vuejs.org/v2/api/#devtools

### `errorHandler` v2
[`errorHandler`][errorHandler]
[errorHandler]: https://vuejs.org/v2/api/#errorHandler

### `warnHandler` v2
[`warnHandler`][warnHandler]
[warnHandler]: https://vuejs.org/v2/api/#warnHandler

### `ignoredElements` v2
[`ignoredElements`][ignoredElements]
[ignoredElements]: https://vuejs.org/v2/api/#ignoredElements

### `keyCodes` v2
[`keyCodes`][keyCodes]
[keyCodes]: https://vuejs.org/v2/api/#keyCodes

### `performance` v2
[`performance`][performance]
[performance]: https://vuejs.org/v2/api/#performance

### `productionTip` v2
[`productionTip`][productionTip]
[productionTip]: https://vuejs.org/v2/api/#productionTip


## Global API
    
### `Vue.extend( options )` v2
[`Vue.extend( options )`][Vue.extend( options )]
[Vue.extend( options )]: https://vuejs.org/v2/api/#Vue-extend

### `Vue.nextTick( [callback, context] )` v2
[`Vue.nextTick( [callback, context] )`][Vue.nextTick( [callback,context )]
[Vue.nextTick( [callback,context )]: https://vuejs.org/v2/api/#Vue-nextTick

Defer the callback to be executed after the next DOM update cycle. Use it immediately after you’ve changed some data to wait for the DOM update.

	// modify data
	vm.msg = 'Hello'
	// DOM not updated yet
	Vue.nextTick(function () {
	  // DOM updated
	})

	// usage as a promise (2.1.0+, see note below)
	Vue.nextTick().then(function () {
	    // DOM updated
	})

因为 $nextTick() 返回一个 Promise 对象，所以你可以使用新的 ES2016 async/await 语法完成相同的事情：

	methods: {
	  updateMessage: async function () {
	    this.message = '已更新'
	    console.log(this.$el.textContent) // => '未更新'
	    await this.$nextTick()
	    console.log(this.$el.textContent) // => '已更新'
	  }
	}

### `Vue.set( target, propertyName/index, value )` v2
[`Vue.set( target, propertyName/index, value )`][Vue.set( target, propertyName/index, value )]
[Vue.set( target, propertyName/index, value )]: https://vuejs.org/v2/api/#Vue-set

### `Vue.delete( target, propertyName/index )` v2
[`Vue.delete( target, propertyName/index )`][Vue.delete( target, propertyName/index )]
[Vue.delete( target, propertyName/index )]: https://vuejs.org/v2/api/#Vue-delete

### `Vue.directive( id, [definition] )` v2
[`Vue.directive( id, [definition] )`][Vue.directive( id, definition )]
[Vue.directive( id, definition )]: https://vuejs.org/v2/api/#Vue-directive

### `Vue.filter( id, [definition] )` v2
[`Vue.filter( id, [definition] )`][Vue.filter( id, definition )]
[Vue.filter( id, definition )]: https://vuejs.org/v2/api/#Vue-filter

### `Vue.component( id, [definition] )` v2
[`Vue.component( id, [definition] )`][Vue.component( id, definition )]
[Vue.component( id, definition )]: https://vuejs.org/v2/api/#Vue-component

### `Vue.use( plugin )` v2
[`Vue.use( plugin )`][Vue.use( plugin )]
[Vue.use( plugin )]: https://vuejs.org/v2/api/#Vue-use

### `Vue.mixin( mixin )` v2
[`Vue.mixin( mixin )`][Vue.mixin( mixin )]
[Vue.mixin( mixin )]: https://vuejs.org/v2/api/#Vue-mixin
[Global Mixin]: https://vuejs.org/v2/guide/mixins.html#Global-Mixin

插件开发过程中可以使用混入 [Global Mixin] 将外部对象与 Vue 组件融合，但这种方法的代码管理比较混乱，不是一种推荐的编程模式。


### `Vue.compile( template )` v2
[`Vue.compile( template )`][Vue.compile( template )]
[Vue.compile( template )]: https://vuejs.org/v2/api/#Vue-compile

手动编译模板字符串，得到结果就是一个渲染函数 render function，此功能函数需要在全功能版中使用，如是在单文件组件开发模式下需要开启配置文件中的 `runtimeCompiler: true` 来支持运行时编译，尽管这会降低运行效率并增加js文件大小，参考 [Render]、 [Vue CLI 配置参考]。

	var res = Vue.compile('<div><span>{{ msg }}</span></div>')
 
	new Vue({
	  data: {
	    msg: 'hello'
	  },
	  render: res.render,
	  staticRenderFns: res.staticRenderFns
	})


### `Vue.observable( object )` v2
[`Vue.observable( object )`][Vue.observable( object )]
[Vue.observable( object )]: https://vuejs.org/v2/api/#Vue-observable
[Data and Methods]: https://vuejs.org/v2/guide/instance.html#Data-and-Methods
[Reactivity in Depth]: https://vuejs.org/v2/guide/reactivity.html

在 Vue 2.x 中，`Vue.observable` 直接将参数传入的对象封装成响应式数据对象，直接供渲染函数和计算属性使用，参考 [Data and Methods]、[Reactivity in Depth]。在 Vue 3.x 中，数据的响应式能力将由 ES6 中的代理对象 Proxy 实现。为了良好的兼容，建议使用 Vue.observable 来返回响应式对象。

	const state = Vue.observable({ count: 0 })

	const Demo = {
	  render(h) {
	    return h('button', {
	      on: { click: () => { state.count++ }}
	    }, `count is: ${state.count}`)
	  }
	}

### `Vue.version` v2
[`Vue.version`][Vue.version]
[Vue.version]: https://vuejs.org/v2/api/#Vue-version

	var version = Number(Vue.version.split('.')[0])

	if (version === 2) {
	  // Vue v2.x.x
	} else if (version === 1) {
	  // Vue v1.x.x
	} else {
	  // Unsupported versions of Vue
	}

## Options / Data
    
### `data` v2
[`data`][data]
[data]: https://vuejs.org/v2/api/#data

### `props` v2
[`props`][props]
[props]: https://vuejs.org/v2/api/#props

### `propsData` v2
[`propsData`][propsData]
[propsData]: https://vuejs.org/v2/api/#propsData

### `computed` v2
[`computed`][computed]
[computed]: https://vuejs.org/v2/api/#computed

### `methods` v2
[`methods`][methods]
[methods]: https://vuejs.org/v2/api/#methods

### `watch` v2
[`watch`][watch]
[watch]: https://vuejs.org/v2/api/#watch


## Options / DOM
    
### `el` v2
[`el`][el]
[el]: https://vuejs.org/v2/api/#el

### `template` v2
[`template`][template]
[template]: https://vuejs.org/v2/api/#template

### `render` v2
[`render`][render]
[render]: https://vuejs.org/v2/api/#render

原型：(createElement: () => VNode) => VNode

字符串模板的代替方案，允许你发挥 JavaScript 最大的编程能力。该渲染函数接收一个 createElement 方法作为第一个参数用来创建 VNode。

如果组件是一个函数组件，渲染函数还会接收一个额外的 context 参数，为没有实例的函数组件提供上下文信息。

Vue 选项中的 render 函数若存在，则 Vue 构造函数不会从 template 选项或通过 el 选项指定的挂载元素中提取出的 HTML 模板编译渲染函数。

参考 [渲染函数 & JSX](https://cn.vuejs.org/v2/guide/render-function.html)

### `renderError` v2
[`renderError`][renderError]
[renderError]: https://vuejs.org/v2/api/#renderError


## Options / Lifecycle Hooks
    
参考[生命周期图]参考[生命周期图]
参考[生命周期]: https://vuejs.org/v2/guide/instance.html#Lifecycle-Diagram

### `beforeCreate` v2
[`beforeCreate`][beforeCreate]
[beforeCreate]: https://vuejs.org/v2/api/#beforeCreate

### `created` v2
[`created`][created]
[created]: https://vuejs.org/v2/api/#created

### `beforeMount` v2
[`beforeMount`][beforeMount]
[beforeMount]: https://vuejs.org/v2/api/#beforeMount

### `mounted` v2
[`mounted`][mounted]
[mounted]: https://vuejs.org/v2/api/#mounted

### `beforeUpdate` v2
[`beforeUpdate`][beforeUpdate]
[beforeUpdate]: https://vuejs.org/v2/api/#beforeUpdate

### `updated` v2
[`updated`][updated]
[updated]: https://vuejs.org/v2/api/#updated

### `activated` v2
[`activated`][activated]
[activated]: https://vuejs.org/v2/api/#activated

### `deactivated` v2
[`deactivated`][deactivated]
[deactivated]: https://vuejs.org/v2/api/#deactivated

### `beforeDestroy` v2
[`beforeDestroy`][beforeDestroy]
[beforeDestroy]: https://vuejs.org/v2/api/#beforeDestroy

### `destroyed` v2
[`destroyed`][destroyed]
[destroyed]: https://vuejs.org/v2/api/#destroyed

### `errorCaptured` v2
[`errorCaptured`][errorCaptured]
[errorCaptured]: https://vuejs.org/v2/api/#errorCaptured


## Options / Assets
    
### `directives` v2
[`directives`][directives]
[directives]: https://vuejs.org/v2/api/#directives

### `filters` v2
[`filters`][filters]
[filters]: https://vuejs.org/v2/api/#filters

### `components` v2
[`components`][components]
[components]: https://vuejs.org/v2/api/#components


## Options / Composition
    
### `parent` v2
[`parent`][parent]
[parent]: https://vuejs.org/v2/api/#parent

### `mixins` v2
[`mixins`][mixins]
[mixins]: https://vuejs.org/v2/api/#mixins

### `extends` v2
[`extends`][extends]
[extends]: https://vuejs.org/v2/api/#extends

### `provide / inject` v2
[`provide / inject`][provide / inject]
[provide / inject]: https://vuejs.org/v2/api/#provide-inject


## Options / Misc
    
### `name` v2
[`name`][name]
[name]: https://vuejs.org/v2/api/#name

### `delimiters` v2
[`delimiters`][delimiters]
[delimiters]: https://vuejs.org/v2/api/#delimiters

### `functional` v2
[`functional`][functional]
[functional]: https://vuejs.org/v2/api/#functional

### `model` v2
[`model`][model]
[model]: https://vuejs.org/v2/api/#model

### `inheritAttrs` v2
[`inheritAttrs`][inheritAttrs]
[inheritAttrs]: https://vuejs.org/v2/api/#inheritAttrs

### `comments` v2
[`comments`][comments]
[comments]: https://vuejs.org/v2/api/#comments


## Instance Properties
    
### `vm.$data` v2
[`vm.$data`][vm.$data]
[vm.$data]: https://vuejs.org/v2/api/#vm-data

### `vm.$props` v2
[`vm.$props`][vm.$props]
[vm.$props]: https://vuejs.org/v2/api/#vm-props

### `vm.$el` v2
[`vm.$el`][vm.$el]
[vm.$el]: https://vuejs.org/v2/api/#vm-el

### `vm.$options` v2
[`vm.$options`][vm.$options]
[vm.$options]: https://vuejs.org/v2/api/#vm-options

### `vm.$parent` v2
[`vm.$parent`][vm.$parent]
[vm.$parent]: https://vuejs.org/v2/api/#vm-parent

### `vm.$root` v2
[`vm.$root`][vm.$root]
[vm.$root]: https://vuejs.org/v2/api/#vm-root

### `vm.$children` v2
[`vm.$children`][vm.$children]
[vm.$children]: https://vuejs.org/v2/api/#vm-children

### `vm.$slots` v2
[`vm.$slots`][vm.$slots]
[vm.$slots]: https://vuejs.org/v2/api/#vm-slots

### `vm.$scopedSlots` v2
[`vm.$scopedSlots`][vm.$scopedSlots]
[vm.$scopedSlots]: https://vuejs.org/v2/api/#vm-scopedSlots

### `vm.$refs` v2
[`vm.$refs`][vm.$refs]
[vm.$refs]: https://vuejs.org/v2/api/#vm-refs

### `vm.$isServer` v2
[`vm.$isServer`][vm.$isServer]
[vm.$isServer]: https://vuejs.org/v2/api/#vm-isServer

### `vm.$attrs` v2
[`vm.$attrs`][vm.$attrs]
[vm.$attrs]: https://vuejs.org/v2/api/#vm-attrs

### `vm.$listeners` v2
[`vm.$listeners`][vm.$listeners]
[vm.$listeners]: https://vuejs.org/v2/api/#vm-listeners


## Instance Methods / Data
    
### `vm.$watch( expOrFn, callback, [options] )` v2
[`vm.$watch( expOrFn, callback, [options] )`][vm.$watch( expOrFn, callback, options )]
[vm.$watch( expOrFn, callback, options )]: https://vuejs.org/v2/api/#vm-watch

### `vm.$set( target, propertyName/index, value )` v2
[`vm.$set( target, propertyName/index, value )`][vm.$set( target, propertyName/index, value )]
[vm.$set( target, propertyName/index, value )]: https://vuejs.org/v2/api/#vm-set

### `vm.$delete( target, propertyName/index )` v2
[`vm.$delete( target, propertyName/index )`][vm.$delete( target, propertyName/index )]
[vm.$delete( target, propertyName/index )]: https://vuejs.org/v2/api/#vm-delete


## Instance Methods / Events
    
### `vm.$on( event, callback )` v2
[`vm.$on( event, callback )`][vm.$on( event, callback )]
[vm.$on( event, callback )]: https://vuejs.org/v2/api/#vm-on

监听当前实例上的自定义事件。事件可以由vm.$emit触发。回调函数会接收所有传入事件触发函数的额外参数。

### `vm.$once( event, callback )` v2
[`vm.$once( event, callback )`][vm.$once( event, callback )]
[vm.$once( event, callback )]: https://vuejs.org/v2/api/#vm-once

监听一个自定义事件，但是只触发一次，在第一次触发之后移除监听器。

### `vm.$off( [event, callback] )` v2
[`vm.$off( [event, callback] )`][vm.$off( [event,callback )]
[vm.$off( [event,callback )]: https://vuejs.org/v2/api/#vm-off

移除自定义事件监听器。如果没有提供 `event` 参数，则移除所有的事件监听器；如果只提供了事件，则移除该事件所有的监听器；如果同时提供了事件与回调，则只移除这个回调的监听器。

### `vm.$emit( eventName, […args] )` v2
[`vm.$emit( eventName, […args] )`][vm.$emit( eventName, …args )]
[vm.$emit( eventName, …args )]: https://vuejs.org/v2/api/#vm-emit

触发当前实例上的事件。附加参数都会传给监听器回调。

示例，只配合一个事件名使用 `$emit`：

	<div id="emit-example-simple">
	  <welcome-button v-on:welcome="sayHi"></welcome-button>
	</div>

	Vue.component('welcome-button', {
	  template: `
	    <button v-on:click="$emit('welcome')">
	      Click me to be welcomed
	    </button>
	  `
	})

	new Vue({
	  el: '#emit-example-simple',
	  methods: {
	    sayHi: function () {
	      alert('Hi!')
	    }
	  }
	})

## Instance Methods / Lifecycle
    
### `vm.$mount( [elementOrSelector] )` v2
[`vm.$mount( [elementOrSelector] )`][vm.$mount( elementOrSelector )]
[vm.$mount( elementOrSelector )]: https://vuejs.org/v2/api/#vm-mount

### `vm.$forceUpdate()` v2
[`vm.$forceUpdate()`][vm.$forceUpdate()]
[vm.$forceUpdate()]: https://vuejs.org/v2/api/#vm-forceUpdate

### `vm.$nextTick( [callback] )` v2
[`vm.$nextTick( [callback] )`][vm.$nextTick( callback )]
[vm.$nextTick( callback )]: https://vuejs.org/v2/api/#vm-nextTick

同 `Vue.nextTick( [callback, context] )`，但当前上下文 this 指向当前组件。

### `vm.$destroy()` v2
[`vm.$destroy()`][vm.$destroy()]
[vm.$destroy()]: https://vuejs.org/v2/api/#vm-destroy

触发 `beforeDestroy`、 `destroyed` 两个生命周期函数。通过不必执行这个方法，只需使用数据响应式 `v-if`、`v-for` 就可以做到。

参考[生命周期图]参考[生命周期图]
参考[生命周期]: https://vuejs.org/v2/guide/instance.html#Lifecycle-Diagram

## Directives
    
### `v-text` v2
[`v-text`][v-text]
[v-text]: https://vuejs.org/v2/api/#v-text

### `v-html` v2
[`v-html`][v-html]
[v-html]: https://vuejs.org/v2/api/#v-html

### `v-show` v2
[`v-show`][v-show]
[v-show]: https://vuejs.org/v2/api/#v-show

### `v-if` v2
[`v-if`][v-if]
[v-if]: https://vuejs.org/v2/api/#v-if

### `v-else` v2
[`v-else`][v-else]
[v-else]: https://vuejs.org/v2/api/#v-else

### `v-else-if` v2
[`v-else-if`][v-else-if]
[v-else-if]: https://vuejs.org/v2/api/#v-else-if

### `v-for` v2
[`v-for`][v-for]
[v-for]: https://vuejs.org/v2/api/#v-for

### `v-on` v2
[`v-on`][v-on]
[v-on]: https://vuejs.org/v2/api/#v-on

### `v-bind` v2
[`v-bind`][v-bind]
[v-bind]: https://vuejs.org/v2/api/#v-bind

### `v-model` v2
[`v-model`][v-model]
[v-model]: https://vuejs.org/v2/api/#v-model

### `v-slot` v2
[`v-slot`][v-slot]
[v-slot]: https://vuejs.org/v2/api/#v-slot

### `v-pre` v2
[`v-pre`][v-pre]
[v-pre]: https://vuejs.org/v2/api/#v-pre

### `v-cloak` v2
[`v-cloak`][v-cloak]
[v-cloak]: https://vuejs.org/v2/api/#v-cloak

### `v-once` v2
[`v-once`][v-once]
[v-once]: https://vuejs.org/v2/api/#v-once


## Special Attributes
    
### `key` v2
[`key`][key]
[key]: https://vuejs.org/v2/api/#key

在 v-for 中指定一个唯一键值，避免 Vue 内部就地重用虚拟节点而造成错误的视图渲染结果

	<ul>
	  <li v-for="item in items" :key="item.id">...</li>
	</ul>

### `ref` v2
[`ref`][ref]
[ref]: https://vuejs.org/v2/api/#ref

### `is` v2
[`is`][is]
[is]: https://vuejs.org/v2/api/#is

### `slot` v2
[`slot`][slot]
[slot]: https://vuejs.org/v2/api/#slot-deprecated

### `slot-scope` v2
[`slot-scope`][slot-scope]
[slot-scope]: https://vuejs.org/v2/api/#slot-scope-deprecated

### `scope`] v removed
[`scope`][scope]
[scope]: https://vuejs.org/v2/api/#scope-removed


## Built-In Components
    
### `component` v2
[`component`][component]
[component]: https://vuejs.org/v2/api/#component

### `transition` v2
[`transition`][transition]
[transition]: https://vuejs.org/v2/api/#transition

### `transition-group` v2
[`transition-group`][transition-group]
[transition-group]: https://vuejs.org/v2/api/#transition-group

### `keep-alive` v2
[`keep-alive`][keep-alive]
[keep-alive]: https://vuejs.org/v2/api/#keep-alive

### `slot` v2
[`slot`][slot]
[slot]: https://vuejs.org/v2/api/#slot

## VNode Interface

参考 [VNode class declaration](https://github.com/vuejs/vue/blob/dev/src/core/vdom/vnode.js).


## Server-Side Rendering

参考 [vue-server-renderer package documentation](https://github.com/vuejs/vue/tree/dev/packages/vue-server-renderer).

