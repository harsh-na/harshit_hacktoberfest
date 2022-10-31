<script>
import Header from "./components/Header.svelte";
import List from "./components/List.svelte";
</script>


<style>
.container{
    width:100%;
    background:#0096c7;
}
:global(.container){
    font-family: sans-serif;
}
</style>

<div class="container">
 <Header/>
  <List/>
</div>