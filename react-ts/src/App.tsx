import React, {Component} from 'react';
import logo from './logo.svg';
import './App.css';
import {MobileRender, NormalRender, Portrait, Lanscape, Orientation} from './components/MobileMedia';
import About from './components/About';
import User from './components/User';
import Player from './components/Player';
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
          <p>
            <a className="App-link" href="/love/about">About</a> |&nbsp; 
            <a className="App-link" href="/love/user/Jeango/001">User</a> |&nbsp;
            <a className="App-link" href="/love/player">Player</a> |&nbsp;
            <a
              className="App-link"
              href="/pacman"
              target="_blank"
              rel="noopener noreferrer"
            >
              Pacman
            </a>
          </p>
          <Router history={history}>
            <Route path="/love/about/:args?" component={About}/>
            <Route path="/love/user/:name/:id" component={User}/>
            <Route path="/love/player" component={Player}/>
          </Router>

          <h1>devicePixelRatio {window.devicePixelRatio}|{window.screen.width}|{window.screen.height}</h1>
          <MobileRender><h1>MobileRender</h1></MobileRender>
          <NormalRender><h3>NormalRender</h3></NormalRender>
          <Lanscape><h3>Lanscape Render</h3></Lanscape>
          <Portrait><h3>Portrait Render</h3></Portrait>
          <Orientation><h3>Orientation Render</h3></Orientation>
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
