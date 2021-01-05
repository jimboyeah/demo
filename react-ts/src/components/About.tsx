import React, {Component} from 'react';
import { BrowserRouter, Link } from "react-router-dom";

export default class Demo extends Component 
{
  constructor(props: any){
    super(props);
  }

  render(){
    return About(this.props);
  }
}

function About(props: any) 
{
  console.log("About props:", props);
  let args = props.match.params.args;
  return (
    <div className="card">
      <header className="About-header">
        <p> Edit <code>src/About.tsx</code> and save to reload. </p>
        {args && <p> About { args } </p>}
        <Link to="/about/more...">About</Link> | <Link to="/user/Jack/002">User</Link>
      </header>
    </div>
  );
}

// export default About;
