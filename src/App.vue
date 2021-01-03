<template>
  <div id="app">
    <h1>Welcome to Your Vue.js + TypeScript App</h1>
    <!-- <img alt="Vue logo" src="./assets/logo.png"> -->
    <!-- <HelloWorld msg="Welcome to Your Vue.js + TypeScript App"/> -->
    <p>
    <!-- 使用 router-link 组件来导航，它会被渲染成一个 `<a>` 标签，`to` 属性指定链接 -->
    <!-- IE天生天然残缺，不支持反引号，`/user/${id}/${name}`这样的模板字符串就不能使用了 -->
    <router-link class="button" :to="'/'">Home</router-link> | 
    <router-link class="button" :to="`/user/${id}/${name}`">User</router-link> | 
    <router-link class="button" :to="'/about'">About</router-link>
    </p>
    <!-- 路由视图 路由出口 路由匹配到的组件将渲染在这里 -->
    <router-view></router-view>
    <!-- 命名视图 -->
    <router-view name="secondary"></router-view>
  </div>
</template>

<script lang="ts">
import { Component, Vue } from 'vue-property-decorator';
import HelloWorld from './components/HelloWorld.vue';

@Component({
  data(): any { return {name: 'Jeango', id: 110, stamp: + new Date()}; },
  components: {
    HelloWorld,
  },
})
export default class App extends Vue { }
</script>

<style lang="scss">
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
