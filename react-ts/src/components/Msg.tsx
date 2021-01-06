import {Component} from 'react';
import PropTypes from 'prop-types';
import store from '../store';

interface Props {
    msg?: string;
    onClick?: any;
    dispatch?: any;
}

function Fc(props: any){
    // console.log("Fc render");
    return (
        <div className="card">
            [Function component: {props.msg}]
        </div>
    );
}

class Cc extends Component<Props, {}>
{
    constructor(props: any){
        super(props);
        // console.log('Cc', props, this.state);
    }

    render(){
        // console.log("Cc render");
        return (
            <div className="card">
                [Class Component: {this.props.msg}]
            </div>
        );
    }
}

export default class Demo extends Component<Props, {}>
{
    state = {msg:""}
    static propTypes = {
        msg: PropTypes.string.isRequired
    }
  
    static defaultProps = {
        msg: "..."
    }

    constructor(props: any){
        super(props);
        console.log('Msg', props, this.state, store.getState());
        this.state.msg = props.msg;
        // this.state = props;
    }

    onClick = ()=>{
        this.props.dispatch({ type: 'UPDATE' });
    }

    render(){
        let state = store.getState();
        console.log("msg render", state);
        const { msg, onClick } = this.props;
        return (
            <div className="card">
                [Parent Component: {msg}]
                <button onClick={onClick}>Update</button>
                <Fc {...state} />
                <Cc msg={msg} />
            </div>
        );
    }
}
  