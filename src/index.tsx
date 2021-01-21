import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import reportWebVitals from './reportWebVitals';
import { Router, Route } from 'react-router';
import { createBrowserHistory } from "history";

import Pacman from './pacman';
import Tip from './pacman/tip';

const history = createBrowserHistory();
// <Route path="/love" component={App}/>
ReactDOM.render(
  <React.StrictMode>
    <Router history={history}>
      <Route path="/" component={Tip}/>
      <Route path="/pacman" component={Pacman}/>
    </Router>
  </React.StrictMode>,
  document.getElementById('root')
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
