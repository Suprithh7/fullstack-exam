import React , {useState} from "react";

function ToggleSwitch(){
  const[isOn,setIsOn] = useState(false);


const handletoggle = () =>{
  setIsOn(!isOn);
};

return(

  <div style={{textAlign:"center",
    marginTop:"50px"
  }}>
<h1> React Toggle Switch</h1>

<div onClick={handletoggle}
style={{width:"70px",
  height:"35px",
  position:"relative",
  margin:"auto",
  backgroundColor:isOn ?"green" : "gray",
  borderRadius:"20px",
  transition:"0.3s"
}}>
  <div style={{
    backgroundColor:"white",
    borderRadius:"50%",
    position:"absolute",
    top:"2.5px",
    width:"30px",
    height:"30px",
    transition:"0.3s",
    left:isOn ? "35px" : "4px"
  }}>
  </div>
</div>

<h2> {isOn ? "ON" : "OFF"} </h2>
  </div>
);
}

export default ToggleSwitch;