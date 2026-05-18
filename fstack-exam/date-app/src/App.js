import React, { useState } from "react";

function App() {
  const [name, setName] = useState("");

  const currentDate = new Date().toLocaleDateString();

  return (
    <div
      style={{
        textAlign: "center",
        marginTop: "50px",
        fontFamily: "Arial"
      }}
    >
      <div
        style={{
          width: "350px",
          margin: "auto",
          padding: "20px",
          border: "1px solid black",
          borderRadius: "10px",
          boxShadow: "0px 4px 8px gray",
          backgroundColor: "lightblue",
        }}
      >
        <h1 style={{fontFamily:"italic"}}>React Date App</h1>

        <h2 style={{fontfamily:"italic"}}>Current Date: {currentDate}</h2>

        <input
          type="text"
          placeholder="Enter your name"
          value={name}
          onChange={(e) => setName(e.target.value)}
          style={{
            padding: "10px",
            width: "80%",
            marginTop: "20px",
          }}
        />

        <h2 style={{ marginTop: "20px" }}>
          Welcome, {name}
        </h2>
      </div>
    </div>
  );
}

export default App;