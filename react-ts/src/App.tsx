import React, {Component} from 'react';
import logo from './logo.svg';
import './App.css';
import About from './components/About';
import User from './components/User';
// import Msg  from './components/Msg';
import store, {MsgContainer, Provider} from './store';
// import { connect, Provider } from 'react-redux';
import { Router, Route } from 'react-router';
// import { BrowserRouter, Link } from "react-router-dom";
// import { setInterval } from 'timers';
import { createBrowserHistory } from "history";

const history = createBrowserHistory();

class App extends Component
{
  constructor(props: any){
    super(props);
    console.log("App constructor", props, this.state);
  }

  render() {
    return (
      <div className="App">
        <header className="App-header">
          <img src={logo} className="App-logo" alt="logo" />
          <p>
            Edit <code>src/App.tsx</code> and save to reload.
          </p>
          <p><a href="/about">About</a> | <a href="/user/Jeango/001">User</a></p>
          <Router history={history}>
            <Route path="/about/:args?" component={About}/>
            <Route path="/user/:name/:id" component={User}/>
          </Router>
                      
          <a
            className="App-link"
            href="https://reactjs.org"
            target="_blank"
            rel="noopener noreferrer"
          >
            Learn React
          </a>
        </header>
        <Provider store={store}>
          <MsgContainer />
          <MsgContainer />
        </Provider>

      </div>
    );
  }
}

export default App;
