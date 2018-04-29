let component = ReasonReact.statelessComponent("Todo");

let make = (~todo, ~deleteTodo, ~todoIndex, _self) => {
  ...component,
  render: _self =>
    <li
      onClick={_event => deleteTodo(todoIndex)}
    >
    {ReasonReact.string(todo)}
    </li>,
};
