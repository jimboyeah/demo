import Vue from 'vue';
import Vuex from 'vuex';

Vue.use(Vuex);

export default new Vuex.Store({
  state: {
    msg: 'Loading...',
  },
  mutations: {
    // execute mutaions from user components:
    // this.$store.commit('setMsg', 'Test!'); 
    loading(state) {
      state.msg = 'Loading...';
    },
    done(state) {
      state.msg = 'Done!';
    },
  },
  actions: {
    // this.$store.dispatch('setMsg', 'dispatch!');
    setMsg(store, payload, c) {
      // store: { dispatch, commit, getters, rootGetters }
      console.log(store, payload);
      this.state.msg = payload;
    },
  },
  modules: {
  },
});
