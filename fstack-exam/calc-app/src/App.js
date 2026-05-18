import React, { useState } from "react";

function Calculator() {
  const [num1, setNum1] = useState("");
  const [num2, setNum2] = useState("");
  const [result, setResult] = useState("");

  const add = () => {
    setResult(Number(num1) + Number(num2));
  };

  const subtract = () => {
    setResult(Number(num1) - Number(num2));
  };

  const multiply = () => {
    setResult(Number(num1) * Number(num2));
  };

  const divide = () => {
    setResult(Number(num1) / Number(num2));
  };

  return (
    <div
      style={{
        textAlign: "center",
        marginTop: "50px",
        fontFamily: "Arial",
      }}
    >
      <h1>Simple Calculator</h1>

      <div
        style={{
          width: "300px",
          margin: "auto",
          padding: "20px",
          border: "1px solid black",
          borderRadius: "10px",
          boxShadow: "0px 4px 8px gray",
        }}
      >
        <input
          type="number"
          placeholder="Enter first number"
          value={num1}
          onChange={(e) => setNum1(e.target.value)}
          style={{
            width: "90%",
            padding: "10px",
            margin: "10px",
          }}
        />

        <input
          type="number"
          placeholder="Enter second number"
          value={num2}
          onChange={(e) => setNum2(e.target.value)}
          style={{
            width: "90%",
            padding: "10px",
            margin: "10px",
          }}
        />

        <div>
          <button onClick={add}>+</button>
          <button onClick={subtract} style={{ marginLeft: "10px" }}>
            -
          </button>
          <button onClick={multiply} style={{ marginLeft: "10px" }}>
            *
          </button>
          <button onClick={divide} style={{ marginLeft: "10px" }}>
            /
          </button>
        </div>
        <div>
          <h2>Result: {result}</h2>
        </div>
      </div>
    </div>
  );
}

export default Calculator;