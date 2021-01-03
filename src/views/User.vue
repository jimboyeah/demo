<template>
  <div class="user">
    <div>Hello {{ $route.params.name }}, your id is {{ $route.params.id }}.</div>
  </div>
</template>

<script>

export default {
  name: 'User',
  components: { },
};
</script>
