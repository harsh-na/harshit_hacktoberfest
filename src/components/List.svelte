<script>
    import { onMount } from "svelte";
    import todoapi from "../todoapi";
    import {items} from "../store";
    import Item from "./items.svelte";
    import NewItem from "./newItem.svelte";
    import {v4 as uuidv4} from "uuid";


    function newItem(e ){
        $items = [
            {
                id: uuidv4(),
                text: e.detail,
                completed: false
            },
            ...$items
        ]
        todoapi.save($items);
    }
    function update(e){

        const indx=$items.findIndex((item)=>item.id===e.detail.id);
        $items[indx] =e.detail;
        todoapi.save($items);
    }
    function remove(e){
        $items = $items.filter(item=>item.id!==e.detail.id); 
        todoapi.save($items);
    }

    let itemsorted = [];

    $: {
        itemsorted = [...$items];
        itemsorted.sort((a,b)=>{
            if(a.completed && !b.completed){
                return 1;
            }
            if(!a.completed && b.completed){
                return -1;
            }
            return 0;
        });
    }

    onMount(async() =>{
        //fetch data from api
        $items = await todoapi.getAll();
        $items =[
            {id:1,text:"test",completed:false}          
        ];
});
</script>


<style>
    .list{
        padding:15px;
    }
    .list-text{
        margin:0;
        text-align:center;
        color :#ffffff;
        font-weight: bold;
        font-size: 1.1rem;
    }
</style>

<div class="list">
    <NewItem on:newitem={newItem} />
    {#each itemsorted as item (item)}
        <Item {...item} on:update={update} on:delete={remove} />
    {:else}
      <p class="list-text">No Items Found</p>
    {/each}
</div>