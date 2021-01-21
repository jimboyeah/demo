import React, {Component} from 'react';
import { Link } from "react-router-dom";

export default class About extends Component 
{
  // constructor(props: any){
  //   super(props);
  // }

  render(){
    return Render(this.props);
  }
}

function Render(props: any) 
{
  console.log("About props:", props);
  let args = props.match.params.args;
  return (
    <div className="card">
      <header className="About-header">
        <p> Edit <code>src/About.tsx</code> and save to reload. </p>
        {args && <p> About { args } </p>}
        <Link to="/love/about/more...">About</Link> | <Link to="/love/user/Jack/002">User</Link>
      </header>
    </div>
  );
}

// export default About;
