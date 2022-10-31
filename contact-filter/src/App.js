import React, { useEffect,  useState } from "react"
import "./App.css"

import ContactCard from ".././src/Components/ContactCard"
const contact=[
  {
    name: "Apple",
    phone: "2222"
  },
  {
    name: "Ball",
    phone: "2222"
  },
  {
    name: "Cat",
    phone: "2222"
  },
  {
    name: "Dog",
    phone: "2222"
  },
  {
    name: "Elephant",
    phone: "2222"
  },
  {
    name: "Fish",
    phone: "2222"
  },
  {
    name: "Abhishek",
    phone: "2222"
  },
]



export default function App(){

  const [result, setResult]=useState([]);
  const [search, setSearch]=useState("");
  // const searchKey = useRef(" ");

  function handleChange(){
    // setSearch(e.target.value)
    // setResult(contact.filter((c)=>{c.name.includes(e.target.value)}));
    console.log("Search Items");
    
    setResult(contact.filter(c=>c.name.toLowerCase().startsWith(search.toLowerCase())));
  }
  useEffect(()=>{
    setResult(contact);
    handleChange();
  console.log(search);
  // eslint-disable-next-line
  },[search]);
  return(
    <div className="main">
      <h1><i class="fas fa-address-card"/> Contact Search</h1>
      
      <input type="search"  onChange={(e)=>setSearch(e.target.value)} />
      <div className="contactContainer" >
        {result.map((response)=>{
          return(
            <ContactCard
              name={response.name}
              phone={response.phone}
            />
          )
        })}
      </div>
    </div>
  )
}