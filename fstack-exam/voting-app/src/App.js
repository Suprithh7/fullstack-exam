import React, { useState } from "react";

function VotingApp() {
  const [person1, setPerson1] = useState(0);
  const [person2, setPerson2] = useState(0);
  const [person3, setPerson3] = useState(0);

  let leader = "Tie";

  if (person1 > person2 && person1 > person3) {
    leader = "Rahul";
  } 
  else if (person2 > person1 && person2 > person3) {
    leader = "Priya";
  } 
  else if (person3 > person1 && person3 > person2) {
    leader = "Arjun";
  }

  return (
    <div style={{ textAlign: "center", marginTop: "50px" }}>
      <h1>Voting Application</h1>

      <div
        style={{
          border: "1px solid black",
          padding: "20px",
          width: "200px",
          margin: "10px auto",
          borderRadius: "10px",
        }}
      >
        <h2>Rahul</h2>
        <h3>Votes: {person1}</h3>

        <button onClick={() => setPerson1(person1 + 1)}>
          Vote
        </button>
      </div>

      <div
        style={{
          border: "1px solid black",
          padding: "20px",
          width: "200px",
          margin: "10px auto",
          borderRadius: "10px",
        }}
      >
        <h2>Priya</h2>
        <h3>Votes: {person2}</h3>

        <button onClick={() => setPerson2(person2 + 1)}>
          Vote
        </button>
      </div>

      <div
        style={{
          border: "1px solid black",
          padding: "20px",
          width: "200px",
          margin: "10px auto",
          borderRadius: "10px",
        }}
      >
        <h2>Arjun</h2>
        <h3>Votes: {person3}</h3>

        <button onClick={() => setPerson3(person3 + 1)}>
          Vote
        </button>
      </div>

      <h2>Leading Candidate: {leader}</h2>
    </div>
  );
}

export default VotingApp;