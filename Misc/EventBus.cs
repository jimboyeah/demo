using System;
using System.Collections.Generic;
using System.Threading.Tasks;

namespace AppWeb
{
    public static class EventBus
    {
        private static Dictionary<string, Action<object>> _actions = new Dictionary<string, Action<object>>();

        public static void Add(string type, Action<object> act)
        {
            Remove(type);
            _actions.Add(type, act);
        }

        public static bool Remove(string type)
        {
            if(_actions.ContainsKey(type))
            {
                _actions.Remove(type);
                return true;
            }
            return false;
        }

        public static void Dispatch(string type, object arg)
        {
            if(_actions.ContainsKey(type))
            {
                var act = _actions[type];
                act.Invoke(arg);
            }
        }
    }
}
