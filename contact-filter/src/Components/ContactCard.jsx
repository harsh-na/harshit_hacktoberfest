import React from "react"
import "../CSS/ContactCard.css"

export default function ContactCard(props){
    return(
        <div className="contactCard" >
            <h2>Name: {props.name}</h2>
            <h2>Phone: {props.phone}</h2>
        </div>
    )
}