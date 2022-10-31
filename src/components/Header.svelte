<script>
 import {items} from "../store.js";
 console.log(items);

 $: itemCount = $items.length;
 $: completeditemCount = $items.filter(item => item.completed).length;
</script>

<style>
.header{
    display:flex;
    justify-content:space-between;
    align-items: center;
    padding: 15px 20px;
    color: #ffffff;
    font-weight: bold;
    font-size: 1.2rem;
    background: rgba(0, 0, 0, 0.1);
}
</style>

<div class="header">
    <span>ToDo List</span>
<span>{completeditemCount}/{itemCount}</span>
</div>