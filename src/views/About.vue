<template>
  <div class="about">
    <h1>This is an about page</h1>
    <p>{{ $store.state.msg }}</p>
    <button @click="test">Test</button>
  </div>
</template>
<script lang="ts">
// declare function greet(greeting: string): void;
// import greet from '@/greet.js';

interface LabelledValue {
  label: string;
}

function printLabel(labelledObj: LabelledValue) {
  console.log(labelledObj.label);
}

const myObj = {size: 10, label: '"Size 10 Object"'};
printLabel(myObj);

const m: {size: number, label: string} = myObj;
printLabel(m);

const M: LabelledValue = {label: 'Mad...'};
printLabel(M);

export default {
  name: 'About',
  components: {  },
  methods: {
    // arrow function will captures the global value of 'this'.
    test(event: MouseEvent) {
        console.log(event, this);
        // execute $store.mutaions.done()
        // this.$store.commit('done'); 
        // this.$store.commit('setMsg', 'Test!');
        this.$store.dispatch('setMsg', 'dispatch!');
        // greet('"Hi"');
    },
  },
};
</script>