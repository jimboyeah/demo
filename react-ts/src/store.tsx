import { createStore } from 'redux';
import { connect, Provider } from 'react-redux';
import Msg  from './components/Msg';
/* 
Usage:
    import store, {MsgContainer, Provider} from './store';
    <Provider store={store}>
        <MsgContainer />
        <MsgContainer />
    </Provider>
 */

const MsgContainer = connect(
    // const mapStateToProps,
    (state) => { 
      console.log('connect', state); 
      return state; 
      // return {msg: "state"}; 
    },
    // mapDispatchToProps
    ( dispatch, ownProps ) => {
        return {
          onClick: () => {
            dispatch({ type: 'UPDATE' });
          }
        };
      }
)(Msg);

const reducer = (state = {}, action: {type:string}) => {
    if (typeof state === 'undefined') {
        return {msg:"initialState"};
      }
    
    let ret: any = Object.assign({}, state);
    switch (action.type) {
        case 'UPDATE': ret.msg = "+"+new Date().getSeconds(); break;
        default: break;
    }
    console.log("store reducer", ret, "<---", state, action);
    return ret;
};

const store = createStore(reducer);
// let { subscribe, dispatch, getState } = createStore(reducer);

export default store;
export {connect, Provider, MsgContainer};
