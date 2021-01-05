import React from 'react';
import { BrowserRouter, Link } from "react-router-dom";

function User(props: any) {
  console.log("User props:", props);
  return (
    <div className="card">
      <header className="User-header">
        <p>
          Edit <code>src/User.tsx</code> and save to reload.
        </p>
        <p>User Name: {props.match.params.name} ID: {props.match.params.id}</p>
        <Link to="/about/testing..." onClick={()=>{ }}>About</Link> | 
        <Link to="/user/Rose/003" onClick={()=>{}}>User</Link>
      </header>
    </div>
  );
}

export default User;
