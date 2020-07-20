<template>
	<div class="hello">
		<h1>demo</h1>
		<div v-html="msg">{{ msg }}</div>
		<div v-html="md">{{ md }}</div>
	</div>
</template>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style>
table { border-collapse: collapse; border-radius: 24px; border:1px solid #dadada; box-shadow: 1px solid #282828; }
thead { background: #282828; color: white; }
th {text-align: center;}
td {padding: 4px 16px;}
tr {line-height: 28px;}
tr:nth-child(2n){ background: #efefef;  }
</style>

<style scoped>
div.hello { text-align: left; width:640px; margin: auto; }

h3 {
	margin: 40px 0 0;
}
ul {
	list-style-type: none;
	padding: 0;
}
li {
	display: inline-block;
	margin: 0 10px;
}
a {
	color: #42b983;
}
</style>

<script>
import marked from 'marked'

var rendererMD = new marked.Renderer();
	marked.setOptions({
		renderer: rendererMD,
		gfm: true,
		tables: true,
		breaks: false,
		pedantic: false,
		sanitize: false,
		smartLists: true,
		smartypants: false
	});

var demo = marked('I am using __markdown__.')

export default {
	name: 'HelloWorld',
	props: {
		msg: String,
	},
	data: function(){
		return {
			md: demo
		};
	},
	// beforeCreate:	function(){ this.md += " -> beforeCreate"; },
	// created:		function(){ this.md += " -> created"; },
	// beforeMount:	function(){ this.md += " -> beforeMount"; },
	// mounted:		function(){ this.md += " -> mounted"; },
	// beforeDestroy:	function(){ this.md += " -> beforeDestroy"; },
	// destroyed:		function(){ this.md += " -> destroyed"; },
	beforeMount: function(){
		this.msg = marked(this.msg);
	},
	methods:{
	}
}


</script>
