<script>
import {createEventDispatcher} from "svelte";

const dispatch = createEventDispatcher();

let value="";

function handlekeyup({ key }){
    if(key!=='Enter' || value.length===0){
        return;
    }
    dispatch("newitem" , value);
    value="";
}
</script>

<style>
input {
    box-sizing: border-box;
    margin-bottom: 15px;
    padding: 15px;
    border: none;
    outline: none;
    width: 100%;
    background: #48bfe3;
    color: #ffffff;
    font-weight: bold;
    font-size: 1em;
    cursor: pointer;
  }

  input,
  input::placeholder {
    color: #ffffff;
    text-align: center;
  }
</style>

<input type="text" on:keyup={handlekeyup} bind:value placeholder="+ Add Item" />