<script>
// @ts-nocheck

    import {createEventDispatcher} from "svelte";
    export let id, text, completed;

    const dispatch = createEventDispatcher();
    function triggerUpdate() {
        dispatch("update", {
            id,
            text,
            completed
        });
    }

    function dbclick(){
        const yes = confirm("Are you sure you want to delete this item?");
        if(yes){
            dispatch("delete", {
                id
            });
        }
    }
</script>

<style>
    .item{
        display: flex;
        align-items: center;
        padding: 15px;
        background: #ffffff;
    }
    .item:focus-within{
        background: #ade8f4; 
    }
    .item.completed {
        background: #dddddd;
    }

    .item.completed .text-inp {
        color: #666666;
        text-decoration: line-through;
    }
    .text-inp{
        flex-grow:1;
        background: none;
        border: none;
        outline: none;
        font-size: 1.1em;
        font-weight: 500;
    }
    .check-inp {
        margin-left: 15px;
    }
</style>

<div class="item" class:completed on:dblclick={dbclick}>
    <input class="text-inp" type="text"
     bind:value={text} readonly={completed}
     on:keyup={({key,target}) => key==='Enter' && target.blur()} 
     on:blur={()=>triggerUpdate() }/>
    <input class="check-inp" type="checkbox" bind:checked={completed}
     on:change={() => triggerUpdate()} />    
</div>