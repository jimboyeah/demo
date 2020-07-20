
	==========================================================================================
# vue readme & iview readme 前端框架 ===============================================================
	==========================================================================================

vue组件最佳实践 - https://www.cnblogs.com/wenJiaQi/p/6528306.html
				 https://pablohpsilva.github.io/vuejs-component-style-guide/#/

# 单文件组件概念
https://vuejs.org/v2/guide/single-file-components.html

将脚本模板样式三合为一，以单个 vue 文件来编写组件。

In many Vue projects, global components will be defined using Vue.component, followed by new Vue({ el: '#container' }) to target a container element in the body of every page.

This can work very well for small to medium-sized projects, where JavaScript is only used to enhance certain views. In more complex projects however, or when your frontend is entirely driven by JavaScript, these disadvantages become apparent:

Global definitions force unique names for every component
String templates lack syntax highlighting and require ugly slashes for multiline HTML
No CSS support means that while HTML and JavaScript are modularized into components, CSS is conspicuously left out
No build step restricts us to HTML and ES5 JavaScript, rather than preprocessors like Pug (formerly Jade) and Babel

All of these are solved by single-file components with a .vue extension, made possible with build tools such as Webpack or Browserify.

# 基本模板语法

	+ 数据绑定最常见的形式就是使用 {{...}}（双大括号）的文本插值
	template: ` <div>{{ count }}</div> `

	+ HTML 属性中的值应使用 v-bind 指令，模板变量不用双花括号。下为判断 cancss 的值，如果为 true 使用 class1 类的样式，否则不使用
	<div v-bind:class="{'class1': cancss}"> cancss </div>
	<div v-bind:class="[activeClass, errorClass]">可以是数组 </div>
	<div v-bind:style="{ color: activeColor, fontSize: fontSize + 'px' }"> inline-style 内联样式 </div>
	<div v-bind:style="styleObject"> 多个样式对象 styleObject 类似于 { color: 'green' } </div>
	<div v-bind:style="[baseStyles, overridingStyles]"> 多个样式对象 </div>
	<!-- 当 v-bind:style 使用需要特定前缀的 CSS 属性时，如 transform ，Vue.js 会自动侦测并添加相应的前缀。 -->
	<img v-bind:src="imagepath" />
	<a v-bind:href="url"> 菜鸟教程 </a>
	<a :href="url"> 缩写语法 </a>

	+  v-html 指令用于输出 html 代码
	<div v-html="rawHtml"></div>

	+ 在 input 输入框中我们可以使用 v-model 指令来实现双向数据绑定
	<input type="checkbox" v-model="isWeixin" >

	v-model其实就是v-bind:checked的语法糖(参考官方文档)，所以代码里面混用的v-bind:checked="xxx"和v-model="xxx"的用法不是正确的，在subchk节点的操作被Vue内部处理成了v-model相关的逻辑了。
	https://cn.vuejs.org/v2/guide/forms.html
	http://www.runoob.com/vue2/vue-forms.html

	+ Vue.js 都提供了完全的 JavaScript 表达式支持。
	<div id="app">
	    {{5+5}}<br>
	    {{ ok ? 'YES' : 'NO' }}<br>
	    {{ message.split('').reverse().join('') }}
	    <div v-bind:id="'list-' + id">菜鸟教程</div>
	</div>

	+ v-if 条件判断 v-else-if 要求 vue 2.1.0+
	<p v-if="seen"> 看到我了 </p>
	<p v-else-if="watch"> 看到她了 </p>
	<p v-else> 看到它了 </p>
	注意条件中的元素要前后紧接，不能被其它元素隔开。

	+  v-show 指令来根据条件展示元素：
	<h1 v-show="isGreeting">Hello!</h1>

	+ 循环使用 v-for 指令，有两种语法格式。 item in items 形式语法，items 是源数据数组或迭代对象甚至是迭代整数，并且 item 是数组元素迭代的别名。
	<ol> <li v-for="i in 10"> {{ i }} </li> </ol>
	<ol> <li v-for="item in items"> {{ item.name }} </li> </ol>
	<ol> <li v-for="(value, index) in items"> {{ index + "-" +value.name }} </li> </ol>
	<ul> <li v-for="(value, key, [index]) in object"> {{ key }} : {{ value }} </li> </ul>
    <div v-for="item in items">{{ $index }} - {{ item.message }}</div>

	<a v-for="(item,index) in items" v-on:click="onclick(event,index)">{{ index }}{{ item.text }} vue 2.0</a>
	<a v-for="(index,item) in items" data-index="{{index}}" v-on:click="onclick(event, $index)">{{ item.text }} vue 1.0</a>
	onclick:function(event){
	    event.preventDefault();
	    let target = event.target
	    console.log(target.getAttribute("data-index"));
	    document.getElementById('index').value = target.getAttribute("data-index");
	}


	+ v-on 监听事件，并对用户的输入进行响应。
    <button v-on:click="doClick">Click Me</button>
	<a @click="doClick">缩写语法</a>
	<div @click.stop="doClick()">阻止冒泡方法</div>
	<div @click="doClick($event)">事件对象引用</div>
	<div @contextmenu.prevent="show2()">右键</div>
	<div @contextmenu="show2($event)">右键</div>



	+ 修饰符是以半角句号 . 指明的特殊后缀，用于指出一个指令应该以特殊方式绑定。例如 .prevent 等效 event.preventDefault()：
	<form v-on:submit.prevent="onSubmit"></form>

	<!-- 阻止单击事件继续传播 -->
	<a v-on:click.stop="doThis"></a>

	self  只点自己身上才运行
	<div @click="parent">parent
        <div @click.self="child">child
            <div @click="grandson">grandson</div>
        </div>
    </div>
    
	<!-- 提交事件不再重载页面 -->
	<form v-on:submit.prevent="onSubmit"></form>

	<!-- 修饰符可以串联 -->
	<a v-on:click.stop.prevent="doThat"></a>

	<!-- 只有修饰符 -->
	<form v-on:submit.prevent></form>

	<!-- 添加事件监听器时使用事件捕获模式 -->
	<!-- 即元素自身触发的事件先在此处处理，然后才交由内部元素进行处理 -->
	<div v-on:click.capture="doThis">...</div>

	<!-- 只当在 event.target 是当前元素自身时触发处理函数 -->
	<!-- 即事件不是从内部元素触发的 -->
	<div v-on:click.self="doThat">...</div>
	
	<!-- 点击事件将只会触发一次 -->
	<a v-on:click.once="doThis"></a>
	不像其它只能对原生的 DOM 事件起作用的修饰符，.once 修饰符还能被用到自定义的组件事件上。如果你还没有阅读关于组件的文档，现在大可不必担心。

	<!-- the scroll event will not cancel the default scroll behavior -->
	<div v-on:scroll.passive="onScroll">...</div>
	Vue 为这些修饰符额外提供了 .passive 修饰符来提升移动端的性能。举个例子，在滚动的时候，浏览器会在整个事件处理完毕之后再触发滚动，因为浏览器并不知道这个事件是否在其处理函数中被调用了 event.preventDefault()。.passive 修饰符用来进一步告诉浏览器这个事件的默认行为不会被取消。

	不要把 .passive 和 .prevent 一起使用。被动处理函数无法阻止默认的事件行为。

	native修饰符用在组件的根元素上监听一个原生事件，在普通的HTML标签监听一个事件.native 修饰符是不会起作用的。如router-link会阻止click事件，你可以试试只用click不用native,事件是不会触发的。router-link上添加事件的话需要@click.native。

	+ Vue.js 允许你自定义过滤器，被用作一些常见的文本格式化。由"管道符"指示, 过滤器函数接受表达式的值作为输入，格式如下：
	<!-- 在两个大括号中 -->
	{{ message | capitalize }}

	<!-- 在 v-bind 指令中 -->
	<div v-bind:id="rawId | formatId"></div>
	
	过滤器可以串联：
	{{ message | filterA | filterB }}
	
	过滤器是函数可以接受参数，这里 message 是第一个参数，arg2 是表达式的值将被求值然后传给过滤器作为第三个参数。
	{{ message | filterA('arg1', arg2) }}
	

# 表单选择项状态绑定
http://www.runoob.com/vue2/vue-forms.html

	<!DOCTYPE html>
	<html>
		<head>
			<meta charset="utf-8">
			<title>Vue 表单测试实例</title>
			<script src="https://cdn.staticfile.org/vue/2.2.2/vue.min.js"></script>
		</head>
		<body>
			<div id="app" class="panel">

				<div class="well">
					<p>单选框：</p>
					<input type="radio" value="ABC" name="group" v-model="radio">
					<input type="radio" value="XYZ" name="group" v-model="radio">
					<label for="checkbox">{{ radio }}</label>
				</div>

				<div class="well">
					<p>单个复选框：</p>
					<input type="checkbox" value="true" id="checkbox1" v-model="listA">
					<label for="checkbox1">{{ listA }}</label>
					<input type="checkbox" value="false" id="checkbox2" v-model="listB">
					<label for="checkbox2">{{ listB }}</label>
				</div>

				<div class="well">
					<p>多个复选框：</p>
					<input type="checkbox" id="vue" value="Vue" v-model="checkedNames">
					<label for="vue">vue</label>
					<input type="checkbox" id="bootstrap" value="Bootstrap" v-model="checkedNames">
					<label for="bootstrap">Bootstrap</label>
					<p>选择的值为: {{ checkedNames }}</p>
				</div>

				<div class="well">
					<select v-model="selected" name="strawberry">
					<option value="">单选选择</option>
					<option value="vue">vue</option>
					<option value="bootstrap">bootstrap</option>
					</select>
					<p>选择的是: {{selected}}</p>
				</div>

				<div class="well">
					<select multiple v-model="multiple" name="strawberry">
					<option value="">多选列表</option>
					<option value="vue">vue</option>
					<option value="bootstrap">bootstrap</option>
					</select>
					<p>选择的是: {{multiple}}</p>
				</div>

			</div>
		</div>
		<script>
		new Vue({
			el: '#app',
			data: {
				radio : "XYZ",
				listA : "true",
				listB : "true",
				selected : '',
				multiple : ['vue','bootstrap'],
				checkedNames: []
			}
		})
		</script>
	</body>
	</html>


# vue 数据双向绑定

vue实现双向数据绑定的原理就是利用了 Object.defineProperty() 这个方法重新定义了对象获取属性值(get)和设置属性值(set)的操作来实现的。

在MDN上对该方法的说明是：Object.defineProperty() 方法会直接在一个对象上定义一个新属性，或者修改一个对象的现有属性， 并返回这个对象。

它接收三个参数，要操作的对象，要定义或修改的对象属性名，属性描述符。重点就是最后的属性描述符。

属性描述符是一个对象，主要有两种形式：数据描述符和存取描述符。这两种对象只能选择一种使用，不能混合两种描述符的属性同时使用。上面说的get和set就是属于存取描述符对象的属性。

然后我们可以通过在存取描述符中的get和set方法内写入自定义的逻辑来实现对象获取属性和设置属性时的行为。

	var keyValue = 1;
	var obj = {};
	Object.defineProperty(obj,'key', {
	    enumerable: true,
	    configurable: true,
	    get: function(){
	        return keyValue;
	    },
	    set: function(newValue){
	        keyValue = newValue;
	        console.log(`keyValue changed: ${keyValue}`);
	    }
	});

	obj.key; // 1

	obj.key = 'new keyValue';
	// keyValue changed: new keyValue

	keyValue; // "new keyValue"


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


vue全家桶是Vue和 Vue-router，Vuex，axios 插件组合的统称，这四个组合在一起可以算是一个全功能前端开发配置，VueRouter 做SPA单页面应用，Vuex 做数据仓库状态管理，axios 做ajax应用。ivew则是基于vue的ui组件库，类似ui组件库还有 elment, mint-ui等。

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


# webpack基础 优化打包发布 去掉#号 页面空白问题

+ webpack 基础
https://github.com/ruanyf/webpack-demos
https://webpack.js.org/concepts/
http://www.ruanyifeng.com/blog/2018/03/node-debugger.html
http://www.ruanyifeng.com/blog/2016/09/react-technology-stack.html

webpack总得来说是一个js打包工具，它的思想是模块化思想，不管你是js，css，还是scss，less，还是jsx，webpack统统都能打包。在webpack看来一切都是模块！有合适的loaders，它们都可以被当做模块被处理。

+ webpack的基本概了解

Entry    即打包后运行入口，默认是 ./src/index.js，可以在配置文件中修改。
Output   出口打包文件即打包生成的文件，默认在 ./dist/main.js，可以通过配置修改。
Mode     模式设置，基本上有 development, production, none 几种模式。根据不同的模式使用不同的配置文件来优化开发/发布。

Loaders  加载器， webpack 只认 JavaScript 和 JSON，通过 Loaders 可以让 webpack 以模块的形式加载其它资源，加载器负责资源内容的转换。最简单的加载器配置只需要 test 和 use 两项。

	module: {
		rules: [
			{ test: /\.txt$/, use: 'raw-loader' }
		]
	}

上面这个规则配置告诉 webpack 在打包时，遇到 require()/import 中的 txt 文本文件要使用 raw-loader 处理。

除了加载器，webpack 还提供了插件接口，插件是 webpack 的基本骨架。以 html-webpack-plugin 这个插件为例，首先通过 npm 安装它，需要使用时通过 require 引入。

	const HtmlWebpackPlugin = require('html-webpack-plugin'); //installed via npm
	const webpack = require('webpack'); //to access built-in plugins

	module.exports = {
		module: {
			rules: [
				{ test: /\.txt$/, use: 'raw-loader' }
			]
		},
		plugins: [
			new HtmlWebpackPlugin({template: './src/index.html'})
		]
	};

In the example above, the html-webpack-plugin generates an HTML file for your application by injecting automatically all your generated bundles.

There are many plugins that webpack provides out of the box! Check out the list of plugins.
Using plugins in your webpack config is straightforward - however, there are many use cases that are worth further exploration. Learn more about them here.



浏览器兼容，webpack 支持基于 ES5 的浏览器 (IE8 and below are not supported)，这是因为 webpack 使用 Promise 来实现 import() require.ensure()。如果要兼容旧浏览器，可以考虑使用 polyfill。

webpack项目文件有三大组成，package.json 是项目依赖包，webpack.config.js 是打包配置文件，脚本文件，VUE项目包含 server.js 自带的服务器用来在本机进行调试。package.json 也是 npm 的配置信息文件，建议了解一些 npm 脚本基础。如 scripts 中配置的是命令，通过 npm run 执行脚本命令时，会新建一个 shell 来执行这里配置的命令，所以只要系统认识的命令都可以在这配置。另外 npm 提供了 pre & post 钩子机制，如 npm run build 执行时，简写成 npm build，它可以按顺序调用以下三个脚本：

	"prebuild": "echo I run before the build script",
	"build": "cross-env NODE_ENV=production webpack",
	"postbuild": "echo I run after the build script"

使用钩子可以用来做一些前期或后期动作，如清理工作，像 clean-webpack-plugin 这种插件就是一行脚本配置的事。清理脚本也可以这样写脚本：

	"clean": "rimraf ./dist && mkdir dist",
	"prebuild": "npm run clean",
	"build": "cross-env NODE_ENV=production webpack"

如果脚本中需要执行多组命令，& 可以用来连接命令，写成 a & b，它会按前后顺序运行命令 a 和 b。而 a && b 则会在 a 命令成功后才执行 b 命令。npm 脚本有一个非常强大的功能，就是可以使用 npm 的内部变量。 通过环境变量process.env对象，拿到package.json配置信息，再通过npm_package_前缀可以获取配置文件内的配置项，如脚本中读取 name & version 等信息：

	console.log(process.env.npm_package_name);
	console.log(process.env.npm_package_version);
	console.log(process.env.npm_package_scripts_build);

以下是常用脚本，参考：
http://www.ruanyifeng.com/blog/2016/10/npm_scripts.html

    "prebuild": "del /Q dist\\*",
	"clean": "rimraf dist/*", // 删除目录
	"clean": "rimraf dist/*", // 删除目录
	"serve": "http-server -p 9090 dist/", // 本地搭建一个 HTTP 服务
	"open:dev": "opener http://localhost:9090", // 打开浏览器
	"livereload": "live-reload --port 9091 dist/", // 实时刷新
	"build:html": "jade index.jade > dist/index.html", // 构建 HTML 文件
	"watch:css": "watch 'npm run build:css' assets/styles/", // 只要 CSS 文件有变动，就重新执行构建
	"watch:html": "watch 'npm run build:html' assets/html", // 只要 HTML 文件有变动，就重新执行构建
	"deploy:prod": "s3-cli sync ./dist/ s3://example-com/prod-site/", // 部署到 Amazon S3
	"build:favicon": "node scripts/favicon.js", // 构建 favicon


webpack提供两个工具处理样式表，css-loader 和 style-loader，二者处理的任务不同，css-loader使你能够使用类似@import 和 url(...)的方法实现require()的功能,style-loader将所有的计算后的样式加入页面中，二者组合在一起使你能够把样式表嵌入webpack打包后的JS文件中，安装命令：

	npm install --save-dev style-loader css-loader

CSS modules 的技术就意在把JS的模块化思想带入CSS中来，通过CSS模块，所有的类名，动画名默认都只作用于当前模块。Webpack从一开始就对CSS模块化提供了支持，在CSS loader中进行配置后，你所需要做的一切就是把”modules“传递都所需要的地方，然后就可以直接把CSS的类名传递到组件的代码中，且这样做只对当前组件有效，不必担心在不同的模块中具有相同的类名可能会造成的问题。

插件（Plugins）是用来拓展Webpack功能的，它们会在整个构建过程中生效，执行相关的任务。Loaders和Plugins常常被弄混，但是他们其实是完全不同的东西，可以这么来说，loaders是在打包构建过程中用来处理源文件的（JSX，Scss，Less..），一次处理一个，插件并不直接操作单个文件，它直接对整个构建过程其作用。Webpack有很多内置插件，同时也有很多第三方插件，可以让我们完成更加丰富的功能。

Hot Module Replacement（HMR）也是webpack里很有用的一个插件，它允许你在修改组件代码后，自动刷新实时预览修改后的效果，这个特性在开发过程中作用非常巨大。在新版本中，这个插件已经内置了，通过 webpack-dev-server 指定 hot 参数就可以使用：

	webpack-dev-server --content-base ./ --open --inline --hot ...

在 Webpack 4 中，不再强制要求指定 entry 和 output 路径。webpack 4 会默认 entry 为 ./src，output 为 ./dist。


webpack 的配置 webpack.base.config.js 的入口项，把该添加的入口模块都添加上。对于多页应用存在多个入口，entry可以是字符串（单入口），可以是数组（多入口），但为了后续发展，请务必使用object，因为object中的key在webpack里相当于此入口的name，既可以后续用来拼生成文件的路径，也可以用来作为此入口的唯一标识。

    entry: {
        index: './src/index',
        main: './src/main',
        vendors: './src/vendors'
    },

webpack 的输出 output 参数告诉webpack以什么方式来生成输出文件。与entry不同，output相当于一套规则，所有的入口产生的输出文件都必须使用这一套规则，不能针对某一个特定的入口来制定output规则。输出项中用[name]来引用entry每一项中的key，用以批量指定生成后文件的名称。[hash]引用本次编译的一个hash版本，[chunkhash] 引用的是当前chunk的一个hash版本。也就是说，在同一次编译中，每一个chunk的hash都是不一样的；而在两次编译中，如果某个chunk根本没有发生变化，那么该chunk的hash也就不会发生变化。

相对SAP的单面入口，多页应用的每个模块可以对应一个页面，由于多个页面对应多个输出文件，多页应用需要在每个页面中引入公共的 JavaScript 文件以及其自身的 JavaScript 文件。这个引用如果是 CSS 文件，则可以由 extract-text-webpack-plugin 这个插件自动提取并插入到 HTML 页面，对于 HTML 页面中引入 JavaScript 文件则需要使用 html-webpack-plugin 这个插件。以下就是一个页面的配置，多个页面则可以将页面记录在数组中，然后通过脚本枚举生成相应的配置，当然在数量不多的情况下，复制几份配置也是可行的：

    new HtmlWebpackPlugin({
        filename: '../index.html',
        template: './src/template/index.ejs',
        inject: false
    })

	['index','home','login'].forEach((page) => {
	    const htmlPlugin = new HTMLWebpackPlugin({
	        filename: `${page}.html`,
	        template: path.resolve(__dirname, `../src/html/${page}.html`),
	        chunks: [page, 'commons'],
	    });
	    HTMLPlugins.push(htmlPlugin);
	    Entries[page] = path.resolve(__dirname, `../src/js/${page}.js`);
	})


模板的配置参考插件文档，这里稍作引导，原有一个模板内容如下：

    <link rel="stylesheet" href="<%= htmlWebpackPlugin.files.css[0] %>">
    <script type="text/javascript" src="<%= htmlWebpackPlugin.files.js[0] %>"></script>
    <script type="text/javascript" src="<%= htmlWebpackPlugin.files.js[1] %>"></script>

webpack 编译时，会产生输出文件，插件可以获取到相应的文件列表，通过输出列表里的文件信息到模板就可以实现引入脚本文件到页面。js[0] 代表的是 vendor.js 共公部分，js[1] 代表的是 main.js 即入口模块，这里有路由配置信息。js[2], js[3] 则会分别代表两个页面模块生成的输出文件，新建一个模板并且把模板名字设置到插件配置项里就可以完成页面的生成动作。

    <link rel="stylesheet" href="<%= htmlWebpackPlugin.files.css[0] %>">
    <script type="text/javascript" src="<%= htmlWebpackPlugin.files.js[0] %>"></script>
    <script type="text/javascript" src="<%= htmlWebpackPlugin.files.js[1] %>"></script>
    <script type="text/javascript" src="<%= htmlWebpackPlugin.files.js[2] %>"></script>

    new HtmlWebpackPlugin({
        filename: '../TabPane.html',
        template: './src/template/TabPane.ejs',
        inject: false
    })




+ 页面空白问题

新手打包vue项目，并行编译结果出现页面空白问题。一般是因为配置不正确导致的，：

	"main": "index.js",

router路由配置文件夹下index.js的设置，极有可能是没有匹配的路由项导致页面无内容。仔细检查各个路由配置项，需要 VurRouter 的基础自行补课

	// mode:'hash' 
	mode: 'history',//去掉#，
	base: '/app/',  //这个配置也很重要，否则会出现页面空白情况
	scrollBehavior: () => ({ y: 0 }),


+ webpack构建性能优化技巧
http://www.hangge.com/blog/cache/detail_2105.html

对于大型 Vue 项目，或者说项目中引入了许多第三方库，那么在执行 npm run build 构建项目的时候会极其的慢，上几十秒甚至几分钟的时间，特别是开发过程中的时段，这是难以接受的等待。

+ 模块定位 resolve modules

webpack 的 resolve.modules 是用来配置模块库（即 node_modules）所在的位置。当 js 里出现 import 'vue' 这样不是相对、也不是绝对路径的写法时，它便会到 node_modules 目录下去找。在默认配置下，webpack 会采用向上递归搜索的方式去寻找。为了减少搜索范围，可我们以直接写明 node_modules 的全路径。

打开 build/webpack.base.conf.js 文件，添加如下高亮配置：

		resolve: {
		    extensions: ['.js', '.vue', '.json'],
		    modules: [
		      resolve('src'),
		      resolve('node_modules')
		    ],
		    alias: {
		      'vue$': 'vue/dist/vue.esm.js',
		      '@': resolve('src'),
		    }
		},


+ 配置装载机的 include & exclude

webpack 的装载机（loaders）里的每个子项都可以有 include 和 exclude 属性。使用 include 更精确地指定要处理的目录，这可以减少不必要的遍历，从而减少性能损失。同时使用 exclude 对于已经明确知道的，不需要处理的目录，予以排除，从而进一步提升性能。

打开 build/webpack.base.conf.js 文件，添加类似如下配置，例如 easytable 没有在项目使用，则可以把它从 include 中去除。

  rules: [
    {
      test: /\.vue$/,
      loader: 'vue-loader',
      options: vueLoaderConfig,
      include: [resolve('src'), resolve('node_modules/vue-easytable/libs')],
      exclude: /node_modules\/(?!(autotrack|dom-utils))|vendor\.dll\.js/
    },
    {
      test: /\.js$/,
      loader: 'babel-loader',
      include: [resolve('src')],
      exclude: /node_modules/
    },

+ 使用 webpack-parallel-uglify-plugin 插件来压缩代码

默认情况下 webpack 使用 UglifyJS 插件进行代码压缩，但由于其采用单线程压缩，速度很慢。可以改用 webpack-parallel-uglify-plugin 插件，它可以并行运行 UglifyJS 插件，从而更加充分、合理的使用 CPU 资源，从而大大减少构建时间。

执行如下命令安装 webpack-parallel-uglify-plugin

	npm i webpack-parallel-uglify-plugin

打开 webpack.prod.conf.js 文件，并作如下修改：

	const ParallelUglifyPlugin = require('webpack-parallel-uglify-plugin');
	//....
    // 删掉webpack提供的UglifyJS插件
    //new UglifyJsPlugin({
    //  uglifyOptions: {
    //    compress: {
    //      warnings: false
    //    }
    //  },
    //  sourceMap: config.build.productionSourceMap,
    //  parallel: true
    //}),
    // 增加 webpack-parallel-uglify-plugin来替换
    new ParallelUglifyPlugin({
      cacheDir: '.cache/',
      uglifyJS:{
        output: {
          comments: false
        },
        compress: {
          warnings: false
        }
      }
    }),


+ 使用 HappyPack 来加速代码构建

运行在 Node.js 之上的 Webpack 是单线程模型的，所以 Webpack 需要处理的事情只能一件一件地做，不能多件事一起做。而 HappyPack 的处理思路是：将原有的 webpack 对 loader 的执行过程，从单一进程的形式扩展多进程模式，从而加速代码构建。

执行如下命令安装 happypack：

	npm i happypack

打开 build/webpack.base.conf.js 文件，并作类似如下修改：

	const HappyPack = require('happypack');
	const os = require('os');
	const happyThreadPool = HappyPack.ThreadPool({ size: os.cpus().length });
	 
	module.exports = {
	    module: {
	        rules: [{
	            test: /\.js$/,
	            //把js文件处理交给id为 happyBabel 的HappyPack 的实例执行
	            loader: 'happypack/loader?id=happyBabel',
	            include: [path.resolve('src')],
	            //排除node_modules 目录下的文件
	            exclude: /node_modules/
	        }, ]
	    },
	    plugins: [
	        new HappyPack({
	            //用id来标识 happypack处理那里类文件
	            id: 'happyBabel',
	            //如何处理  用法和loader 的配置一样
	            loaders: [{
	                loader: 'babel-loader?cacheDirectory=true',
	            }],
	            //共享进程池
	            threadPool: happyThreadPool,
	            //允许 HappyPack 输出日志
	            verbose: true,
	        })
	    ]
	}


+ 启用DllPlugin和DllReferencePlugin预编译库文件
　　　
这是最复杂也是提升效果最明显的一步，原理是将第三方库文件单独编译打包一次，以后的构建都不需要再编译打包第三方库。项目依赖中通常会引用大量的 npm 包，而这些包在正常的开发过程中并不会进行修改，但是在每一次构建过程中却需要反复的将其解析。

而这两个插件就是用来规避此类损耗的，DllPlugin 插件用来预先编译一些模块，DllReferencePlugin 插件用来引用这些预先编译好的模块。注意：DllPlugin 必须要在 DllReferencePlugin 执行前先执行一次，dll 这个概念应该也是借鉴了 windows 程序开发中的 dll 文件的设计理念。


首先增加 webpack.dll.config.js 配置文件，并在 entry 中配置需要单独DLL化的模块，以下作为示例，据需求裁剪
　　　　
	const path = require('path');
	const webpack = require('webpack');

	module.exports = {
	    entry: {
	        vendor: ['vue/dist/vue.common.js',
	            'vue-router',
	            'axios',
	            'mint-ui',
	            'vue-cordova',
	            '@fortawesome/fontawesome-svg-core',
	            '@fortawesome/free-solid-svg-icons',
	            '@fortawesome/free-regular-svg-icons',
	            '@fortawesome/free-brands-svg-icons',
	            '@fortawesome/vue-fontawesome'
	        ]
	    },
	    output: {
	        path: path.join(__dirname, './dist'),
	        filename: '[name].dll.js',
	        library: '[name]_library' // vendor.dll.js中暴露出的全局变量名
	    },
	    plugins: [
	        new webpack.DllPlugin({
	            path: path.join(__dirname, '/dist/', '[name]-manifest.json'),
	            name: '[name]_library'
	        }),
	        new webpack.optimize.UglifyJsPlugin({
	            compress: {
	                warnings: false
	            }
	        })
	    ]
	};


然后在 webpack.base.conf.js 文件，增加一个插件配置配置，作用是通过 DLLReferencePlugin 来使用 DllPlugin 生成的 DLL Bundle。

	// 添加DllReferencePlugin插件
	new webpack.DllReferencePlugin({
		context: path.resolve(__dirname, '..'),
		manifest: require('./dist/vendor-manifest.json')
	}),


在 package.json 增加构建命令　　

	"dll": "webpack --config webpack.dll.config.js"

执行构建，这一步会生成 vendor-manifest.json 和 static/js/vendor.dll.js

	npm run dll
	npm run dev 或 npm run build
　　
最后在入口页面中 index.html 增加 dll.js 引入，而且必须首先引入，另外将已经独立打包的模块从原有的配置文件 webpack.base.conf.js 中设置为 externals 外部引用

	<script src="/static/js/vendor.dll.js"></script>

	module.exports = {
	    externals: {
	        'echarts': 'echarts',
	        'vue': 'vue',
	        'axios': 'axios',
	        'iview': 'iview'
	    }
	}


+ 提取js/css到cdn优化编译大小

以一个vue项目为例。项目引用了vue、axios、iview、iview的css：

	import Vue from 'vue'
	import App from './App.vue'
	import router from './router'
	import axios from 'axios'
	import iView from 'iview'
	import echarts from 'echarts'
	import 'iview/dist/styles/iview.css'

在 webpack.base.conf.js 中，增加externals配置：


然后在页面文件 index.html 引入cdn资源文件

	<body>
	    <div id="app"></div>
	    <script src="https://cdn.bootcss.com/vue/2.5.2/vue.min.js"></script>
	    <script src="https://cdn.bootcss.com/axios/0.17.1/axios.min.js"></script>
	    <script src="https://cdn.bootcss.com/iview/2.6.0/iview.min.js"></script>
	    <script src="//cdn.staticfile.org/echarts/4.2.0-rc.1/echarts.min.js"></script>
	</body>

将大体积文件放置在cdn上，减小了服务器流量压力，加快了不同地区网页加载速度，如百度图表库 echarts 就很大，压缩后的完整包近一个兆的量。另外使用gzip压缩vendor.js可以有效减小文件体积，一般能压缩70%左右。 



# EventBus通讯

vue中数据的传递大体有以下种方式：

+ vuex（store下的文件）
+ 路由传值（在路由中通过参数传值）
+ 父子组件传值
+ eventbus传值

在vue1.0中，组件之间的通信主要通过vm.$dispatch沿着父链向上传播和用vm.$broadcast向下广播来实现。然而在vue2.0中，已经废除了这种用法。非父子组件之间的通信，可以通过一个空的 Vue 实例作为中央事件总线（事件中心），用他来触发事件和监听事件。

一、在入口 main.js 文件 Vue 初始化中添加一个 data 对象，内写入一个名为 Event 的空 Vue 对象作为中央事件总线

	new Vue({
	  el: '#app',
	  data:{
	    Event: new Vue()
	  },
	  render: h => h(App)
	})

二、在各组件中使用 Vue 的实例属性 $root 来访问根实例，通过事件发射器 $emit 和事件订阅机制 $on 实现兄弟组件通讯。例如在 Hello.vue 组件中想发送数据到 World.vue 组件中，那么数据通过 helloEvent 事件发射出去，由 World.vue 组件订阅接收数据

	<template>
	    <div class="hello">
	        <h3>我是 {{name}} 组件</h3>
	        <button @click="send">发送数据到Vue组件中</button>
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
	            this.$root.Event.$emit('helloEvent',this.name)
	        }
	    }
	}
	</script>

在 World.vue 组件中订阅 helloEvent 事件，在组件销毁生命函数中通过 $off 解除事件订阅

	<template>
	    <div class="world">
	        <h3>我是 {{name}} 组件</h3>
	    </div>
	</template>

	<script>
	export default {
	    data(){
	        return {
	            name: ''
	        }
	    },
	    mounted(){
	        this.$root.Event.$on('helloEvent',name => {
	            this.name = name
	        })
	    },
	    destroy(){
	        this.$root.Event.$off('helloEvent'})
	    }
	}
	</script>




# render function & createComponent
https://vuejs.org/v2/guide/render-function.html
https://cn.vuejs.org/v2/guide/render-function.html

Vue 推荐在绝大多数情况下使用 template 来创建你的 HTML。然而在一些场景中，你真的需要 JavaScript 的完全编程的能力，这就是 render 函数，它比 template 更接近编译器。

render: h => h(App) 这行初始化代码是下面内容的缩写：

	render: function (createElement) {
	    return createElement(App);
	}

缩写形式有以下3种(ES6 语法)：

	render (createElement) {
	    return createElement(App);
	}

	render (h){
	    return h(App);
	}

	render: h => h(App);

其中 根据 Vue.js 作者 Even You 的回复，h 的含义如下：

	It comes from the term "hyperscript", which is commonly used in many virtual-dom implementations. "Hyperscript" itself stands for "script that generates HTML structures" because HTML is the acronym for "hyper-text markup language".

它来自单词 hyperscript，这个单词通常用在 virtual-dom 的实现中。Hyperscript 本身是指生成HTML 结构的 script 脚本，因为 HTML 是 hyper-text markup language 的缩写（超文本标记语言）。个人理解：createElement 函数是用来生成 HTML DOM 元素的，也就是上文中的 generate HTML structures，也就是 Hyperscript，这样作者才把 createElement 简写成 h。

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


关于createElement方法，他是通过render函数的参数传递进来的。它更准确的名字可能是 createNodeDescription，因为它所包含的信息会告诉 Vue 页面上需要渲染什么样的节点，及其子节点。我们把这样的节点描述为“虚拟节点 (Virtual Node)”，也常简写它为“VNode”。VDOM是由 Vue 组件树建立起来的整个 VNode 树的称呼。这个方法有三个参数: 
第一个参数（字符串、对象或函数）主要用于提供dom的html内容。比如传入 "div" 就是创建一个 <div>标签 
第二个参数（类型是对象）主要用于设置这个dom的一些样式、属性、传的组件的参数、绑定事件之类，具体可以参考官方文档 
第三个参数（类型是数组，数组元素类型是VNode）主要用于说是该结点下有其他结点的话，就放在这里。
比如说，有需要分发的标签 <slot>，则通过 this.$slots.default 来获得，或许还有其他组件之类，可能需要被使用的，应该也是放在这里。 

Vue 的模板实际是编译成了 render 函数。这是一个实现细节，通常不需要关心，但如果你想看看模板的功能是怎样被编译的，你会发现会非常有趣。下面是官方文档展示一个使用 Vue.compile 来实时编译模板字符串的简单 demo：

	<div>
		<header> <h1>I'm a template!</h1> </header>
		<p v-if="message"> {{ message }} </p>
		<p v-else-if="info"> {{ info }} </p>
		<p v-else> No message. </p>
	</div>

Vue 编译后产生的 render，可以猜测这个 "_c_" 就是 createElement 的缩写:

	function anonymous() {
		with(this){return _c('div',[_m(0),(message)?_c('p',[_v(_s(message))]):_c('p',[_v("No message.")])])}
	}

	_m(0): function anonymous() {
	  with(this){return _c('header',[_c('h1',[_v("I'm a template!")])])}
	}



# Vue.js生命周期函数（钩子函数）

以下是 vue 2.0 和 1.0 的生命周期函数对比

	vue 1.0			vue 2.0
	init			beforeCreate	:function(){alert('创建前，data和el都还未初始化'); },
	create			create			:function(){alert('完成创建，完成了data数据初始化，el还未初始化'); },
	beforeCompile	beforeMount		:function(){alert('载入前，完成了data和el数据初始化，模板内容还未替换'); },
	compile/ready	mounted			:function(){alert('载入后，载入后html已经渲染，ajax请求可以放在这个函数中'); },
	----			beforeUpdate	:function(){alert('更新前，view层的数据变化前，不是data中的数据改变前'); },
	----			update			:function(){alert('更新后'); },
	----			activated		:function(){alert('keep-alive 组件激活时调用。');},
	----			deactivated		:function(){alert('keep-alive 组件停用时调用。');},
	attached		----
	detached		----
	beforeDestroy	beforeDestroy	:function(){alert('销毁前'); },
	destroy			destroy			:function(){alert('销毁后，Dom元素存在但不受vue控制'); }


# Server-Side Render
https://cn.vuejs.org/v2/guide/ssr.html

SSR 完全指南 https://ssr.vuejs.org/zh/

在 2.3 发布后我们发布了一份完整的构建 Vue 服务端渲染应用的指南。这份指南非常深入，适合已经熟悉 Vue, webpack 和 Node.js 开发的开发者阅读。请移步 ssr.vuejs.org。

Nuxt.js https://nuxtjs.org/

从头搭建一个服务端渲染的应用是相当复杂的。幸运的是，我们有一个优秀的社区项目 Nuxt.js 让这一切变得非常简单。Nuxt 是一个基于 Vue 生态的更高层的框架，为开发服务端渲染的 Vue 应用提供了极其便利的开发体验。更酷的是，你甚至可以用它来做为静态站生成器。

服务端渲染的核心就在于：通过vue-server-renderer插件的renderToString()方法，将Vue实例转换为字符串插入到html文件。

ssr的服务端渲染大致的意思就是vue在客户端将标签渲染成的整个html片段的工作在服务端完成，服务端形成的html片段直接返回给客户端这个过程就叫做服务端渲染。

+ 浏览器加载所有资源(html,css,js,img...)
+ 加载cdn资源
+ vue请求server获取业务数据
+ 返回渲染后的html片段
+ css渲染片段成一个网页

这里面最耗时的请求服务器并返回渲染HTML片段这两步骤，请求serverapi的过程本身除了服务器的限制，还有用户网络，宽带等等诸多限制，并且当页面逻辑过多，数据过于繁琐的情况下，我们的vue在client端渲染也会成为性能瓶颈。如一些电商公司的首页，商品详情页等等。测试这个过程在优化前大概需要500ms左右，即使经过优化也需要200ms左右，这个时间几乎是难以接受的，并且我们在用户网络不是很好的情况下，如果我们serverfetch的过程需要500ms，再加上其他的各种请求资源，手机性能等等，用户就要看到将近一秒的白屏时间，这个明显是很差的用户体验。

在对你的应用程序使用服务器端渲染(SSR)之前，你应该问的第一个问题是，是否真的需要它。这主要取决于内容到达时间(time-to-content)对应用程序的重要程度。例如，如果你正在构建一个内部仪表盘，初始加载时的额外几百毫秒并不重要，这种情况下去使用服务器端渲染(SSR)将是一个小题大作之举。然而，内容到达时间(time-to-content)要求是绝对关键的指标，在这种情况下，服务器端渲染(SSR)可以帮助你实现最佳的初始加载性能。




# H5页面使用 VueRouter 构建SPA单面应用DEMO

VueRouter 实现原理

一个页面地址由协议/主机名/页面地址/查询字符串/hash组成，如

	https://www.host.com/static/index.html?query=123#/user/110

通过浏览器打印以下变量可知道

	location.href   "https://www.host.com/static/index.html?query=123#/user/110"
	location.search "?query=123"
	location.hash   "#/user/110"

通过给 location.href 一个新地址，页面就会刷新跳到指定的地址上，这相当点击一个超链接进入新页面。但是，如果新地址只有hash这部分不同，其它都一样的情况就不同了。地址整体是有变化的，但页面不会刷新跳转。通过脚本可以检测到这种变化，那将这种变化以一定的规则和需要呈现的视图绑定，这就是VueRouter干的事。例如，点击这样一个VueRouter路由链接:

    <router-link to="/user/110">Go to User</router-link>

浏览器地址栏就会改变hash部分：

	#/user/110

DEMO 展示要点

+ VueRouter 的基本使用方法
+ 命名路由，在路由配置项中使用了 name 属性，如 {path: '/user/:userId', name: 'user', component: User }
+ 嵌套路由，通过 children 给路由配置子级路由项目
+ 重定向路由配置项 { path: '/a', redirect: '/b' } 或在 redirect 中使用命名路由 { name: 'foo' }，或一个方法动态返回重定向目标的方法
+ 路由出口组件即生成视图路由结果的视图，<router-view></router-view>
+ 命名视图 <router-view name="specialView"></router-view>，不设置name属性，默认值为 default
+ 多视图路由配置 {path: '/', components: { default: Foo, specialView: User } }
+ <router-link> 路由组件会渲染成a标签，点击 <router-link :to="..."> 等同于调用 router.push(...)。
+ <router-link> 使用命名路由 <router-link :to="{ name: 'user', params: { userId: 123 }}">User</router-link>
+ 编程式的导航 

	router.go(n) 类似 window.history.go(n)。
	router.push(location, onComplete?, onAbort?)
	router.replace(location, onComplete?, onAbort?) 相当声明式 <router-link :to="..." replace>

	router.push('home') // 字符串
	router.push({ path: 'home' }) // 对象
	router.push({ name: 'user', params: { userId: 123 }}) // 命名的路由
	router.push({ path: 'register', query: { plan: 'private' }}) // 带查询参数，变成 /register?plan=private

关于路由嵌套参考
https://router.vuejs.org/zh/guide/essentials/nested-routes.html


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



# Vue 工程使用 VueRouter
https://router.vuejs.org/zh/installation.html

Vue Router 是 Vue.js 官方的路由管理器。它和 Vue.js 的核心深度集成，让构建单页面应用 SPA 变得易如反掌。包含的功能有：

	嵌套的路由/视图表
	模块化的、基于组件的路由配置
	路由参数、查询、通配符
	基于 Vue.js 过渡系统的视图过渡效果
	细粒度的导航控制
	带有自动激活的 CSS class 的链接
	HTML5 历史模式或 hash 模式，在 IE9 中自动降级
	自定义的滚动条行为

在工程目录执行命令安装 vue-router 插件

	npm install vue-router

在工程入口中使用它，通过 Vue.use() 明确地安装路由功能：

	import Vue from 'vue'
	import VueRouter from 'vue-router'

	Vue.use(VueRouter)


# Vuex 状态管理插件DEMO

vuex 状态管理插件基本内容
① 写好的 vue 组件通过（dispatch）触发一些事件或动作( Actions);
② 一般在组件中发出动作是想获取或者改变数据的，但 vuex 中数据是集中管理的，更改数据的动作要提交（Commit）到 Mutations 中；
③ 然后 Mutations 去改变（Mutate）State 中的数据 Mu- 表示 Mutiple 多数据多个动作；
④ 当 State 中的数据被改变之后，就会重新渲染（Render）到 Vue 组件中去，组件展示更新后的数据，完成一个流程。

Vuex 的 核心 是 Store（仓库），相当于是一个容器，一个 Store 实例中包含以下属性的方法：

	state 定义属性（状态 、数据）
	getters 用来获取属性
	actions 定义方法（动作）
	commit 提交变化，修改数据的唯一方式就是显示的提交 mutations
	mutations 定义变化，处理状态（数据）的改变
	mapGetters 用来获取属性（数据）
	mapActions 用来获取方法（动作）

接下来写个DEMO理解 vuex，首先在vue工程目录下执行 npm 命令安装 vuex

	npm install vuex -S

这个命令会下载 vuex 到工程目录的 node_modules\vuex 目录下，并修改根目录下的 package.json 配置文件，添加其中的依赖项

	"dependencies": {
	    "axios": "^0.15.3",
	    "clipboard": "^1.5.12",
	    "echarts": "^3.4.0",
	    "html2canvas": "^0.5.0-beta4",
	    "iview": "^2.7.4",
	    "js-cookie": "^2.1.3",
	    "rasterizehtml": "^1.2.4",
	    "vue": "^2.5.2",
	    "vue-router": "^3.0.1",
	    "vuex": "^3.0.1" <===================== here
	},

在 src 目录下创建 store.js 模块文件作为数据仓库，引入 vuex 并 use，用 state 对像保存定义属性（数据），用它初始化创建一个 Vuex.Store 对象然后导出


	import Vue from 'vue'

	import Vuex from 'vuex'
	Vue.use(Vuex)

	var state = {
	    count:6
	}

	const store = new Vuex.Store({
	    state
	})

	export default store;

在 main.js 文件中导入上面建立的数据仓库并配置到 Vue 实例中。{store,el:'#app'} 这写法是ES6的精简表达式，相当于 {store:store, el:"#app"}。Vue会自动将 store 对象注入到所有子组件中，在子组件中通过 this.$store 访问该 store 数据仓库

	import Vue from 'vue'
	import App from './App.vue'
	import store from './src/store'

	new Vue({
	  store, 
	  el: '#app',
	  render: h => h(App)
	})

新建一个 app.vue 组件，通过 this.$store 访问该数据仓库对象 ，获取该 count 。

	<template>
	  <div id="app">
	    <h1>{{count}}</h1>
	  </div>
	</template>

	<script>
	export default {
	  name: 'app',
	  computed:{
	    count(){
	      return this.$store.state.count
	    }
	  }
	}
	</script>


使用 vuex 提供的 mapGetters，mapActions，mutations 来访问数据
参考：https://www.jianshu.com/p/b014ff74bdb6


① 在 app.vue 中引入 mapGetters，mapActions，mutations 
② 在 app.vue 文件的计算属性中调用 mapGetters 辅助方法，并传入一个数组，在数组中指定要获取的属性  count
③ 在 store.js 中定义好 getters，actions 和 mutations 方法并导出

修改后仓库模块 store.js 内容如下，新建了一套 increment 动作代码，以下代码使用了 ES6 的对象解构语法，和 {obj1,obj2} 这种写法一样，当它们是 function 时，那么 {count:function(state){...}} 就可以简化成 {count(state){...}} 自行补课。

	import Vue from 'vue'
	import Vuex from 'vuex'
	Vue.use(Vuex)

	var state = {
	    count:6
	}

	var getters={
	    count(state){
	        return state.count
	    }
	}

	const actions ={
	    increment({commit,state}){
	        commit('increment') 
	    }
	}

	const mutations ={
	    increment(state){
	        state.count ++;
	    }
	}

	const store = new Vuex.Store({ state, getters, actions, mutations })

	export default store;


在 app.vue 组件中引入也相应引入 mapGetters 和 mapActions 辅助函数，并用 mapActions 来包装数据仓库 store.js 导出的 increment 方法

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




# Vue自定义全局组件(插件)

全局组件: 就是指可以在main.js中使用Vue.use()进行全局引入就可以在其他组件中使用的插件，如 VueRouter

	import VueRouter from 'vue-router'
	Vue.use(VueRouter)

相对普通组件，每次使用时都要引入，像ajax工具组件 axios 就需要在组件vue文件中通过 import 引入。 在入口文件 main.js 通过将 `axios` 添加到 `Vue` 的原型中可以避免在每一个组件文件中进行 import：

	import Vue from 'vue'
	import axios from 'axios'
	Vue.prototype.axios = axios;
	new Vue({
	    el: '#app',
	    render:h => h(App)
	})


至于自定义全局组件，首先写一个demo.vue组件文件，然后写一个index.js引入文件，通过 Vue.component 方法注册全局组件

	// ./component/index.js

	import demo from './src/demo.vue'

	export default {
	    install: (Vue) => {
	        Vue.component('exportComponentName',demo)
	    }
	}

在main.js中导入全局组件，这样就可以直接在其它组件使用插件了。

	imoprt exportComponentName from './component/index.js'

	Vue.use(exportComponentName)

如果要给插件添加全局方法，需要在Vue.propotype即vue原型链上添加方法，在index.js导出对象上书写

	export default {
	    install: (vue) => {
	        Vue.prototype.actionName = (arguments) => {
	            // code
	        }

	        Vue.prototype.actionName2 = (arguments) => {
	            // code
	        }
	        ......
	    }
	}



# iview CDN引入

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


# iview NODE构建方式

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


# 子目录发布图片路径问题

    Vue-CLI 3.5 版本中子目录发布图片路径问题，可以找到模块目录下的选项文件，修改 `publicPath` 即可，开发使用的服务器端口及 IP 地址也可以在 `devServer` 中配置。
	node_modules\@vue\cli-service\lib\options.js
	publicPath: (process.env.NODE_ENV !== 'production'? "/":"/minis/vu/dist/"),


	exports.defaults = () => ({
	  // project deployment base
	  publicPath: '/minis/vu/dist/',
	  // for compatibility concern. TODO: remove in v4.
	  baseUrl: '/',

	  // where to output built files
	  outputDir: 'dist',

	  // where to put static assets (js/css/img/font/...)
	  assetsDir: '',

	  // filename for index.html (relative to outputDir)
	  indexPath: 'index.html',

	  // whether filename will contain hash part
	  filenameHashing: true,

	  // boolean, use full build?
	  runtimeCompiler: false,

	  // deps to transpile
	  transpileDependencies: [/* string or regex */],

	  // sourceMap for production build?
	  productionSourceMap: !process.env.VUE_CLI_TEST,

	  // use thread-loader for babel & TS in production build
	  // enabled by default if the machine has more than 1 cores
	  parallel: hasMultipleCores(),

	  // multi-page config
	  pages: undefined,

	  // <script type="module" crossorigin="use-credentials">
	  // #1656, #1867, #2025
	  crossorigin: undefined,

	  // subresource integrity
	  integrity: false,

	  css: {
	    // extract: true,
	    // modules: false,
	    // localIdentName: '[name]_[local]_[hash:base64:5]',
	    // sourceMap: false,
	    // loaderOptions: {}
	  },

	  // whether to use eslint-loader
	  lintOnSave: true,

	  devServer: {
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
	})
# 代理跨域

使用vue-cli在开发环境中实现跨域步骤 - https://www.jianshu.com/p/abbfe1143ff1
阮一峰老师跨域资源共享 CORS 详解：   
http://www.ruanyifeng.com/blog/2016/04/cors.html
http://www.cnblogs.com/xuange306/p/6185453.html

CORS是一个W3C标准，全称是"跨域资源共享"（Cross-origin resource sharing）。
  
它允许浏览器向跨源服务器，发出XMLHttpRequest请求，从而克服了AJAX只能同源使用的限制。


禁止浏览器安全选项，增加启动参数
在目标后面增加如下的启动参数：

	”chrome.exe" --user-data-dir="c:\ChromeDebug" --test-type --disable-web-security
	"chrome.exe" --remote-debugging-port=9222 --test-type --disable-web-security

表示Chrome会从c:\ChromeDebug中存取用户数据，因该目录可能为空，所以新打开的Chrome-Debug窗口是一个全新的Chrome，没有书签、历史、扩展程序等内容，需要再重新安装扩展程序。


	res.header('Access-Control-Allow-Origin', 'http://localhost:5080');
	// * 这个表示任意域名都可以访问，这样写不能携带cookie了。 || 'http://localhost:5080'

	res.header('Access-Control-Allow-Credentials', true);
	// 允许服务器端发送Cookie数据,
	// 若前端上axios.defaults.withCredentials = true设置为true了，
	// 则Access-Control-Allow-Credentials必须为true,否则会请求失败，报错

   res.header('Access-Control-Allow-Headers', 'Content-Type, Content-Length, Authorization, Accept, X-Requested-With , yourHeaderFeild');
   //它也是一个逗号分隔的字符串，表明服务器支持的所有头信息字段
   res.header('Access-Control-Allow-Methods', 'PUT, POST, GET, DELETE, OPTIONS');  //设置方法
 


新版 Vue-CLI 3.5 的测试服务器在 \node_modules\@vue\cli-service\lib\commands\serve.js

app.all('*', function(req, res, next) {
    res.header("Access-Control-Allow-Origin", "*");
    res.header("Access-Control-Allow-Headers", "X-Requested-With,Content-Type");
    res.header("Access-Control-Allow-Methods","PUT,POST,GET,DELETE,OPTIONS");
    next();
});


vue cli脚手架前端调后端数据接口时候的本地代理跨域问题，如我在本地localhost访问接口http://425.00.100.100:888/是要跨域的，浏览器的安全策略，会报错，在webpack配置一下proxyTable就OK了，如下 config/index.js

	dev: {
    加入以下
    proxyTable: {
      '/api': {
        target: 'http://425.0.100.100:8888/',//设置你调用的接口域名和端口号 别忘了加http
        changeOrigin: true,//如果需要跨域
        pathRewrite: {
          '^/api': '/'
                后面组件中我们掉接口时直接用api代替 比如我要调
                用'http://425.0.100.100:8888/user/add'，直接写‘/api/user/add’即可
        }
      }
    },

作者：星球小霸王
链接：https://www.jianshu.com/p/e36956dc78b8

# vue 可以通过 vue-resource ajax v-for v-bind v-module 双向数据绑定 iview前端框架

vue更新到2.0之后，作者就宣告不再对vue-resource更新，并且vue-resource不支持SSR，所以推荐使用axios, 在服务端和客户端可以同时使用。

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


# 组件示例 button-counter 向父级组件发射事件 $emit() 向组件传递参数 props

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

