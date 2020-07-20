<template>
  <div id="app">
    <img alt="Vue logo" src="./assets/logo.png">
    <HelloWorld msg="Welcome to Your Vue.js App"/>
    <MD :msg="mdcontent"/>
  </div>
</template>

<script>
import HelloWorld from './components/HelloWorld.vue'
import MD from './components/Markdown.vue'
import mddemo from './assets/demo.md'

export default {
  name: 'app',
  data: function(){
    return { mdcontent: mddemo };
    // return { mdcontent: "# Welcome \n Vue.js App" };
  },
  components: {
    HelloWorld, MD
  }
}
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
