let component = ReasonReact.statelessComponent("Todo");

let make = (~todo, _self) => {
  ...component,
  render: _self => <li>{ReasonReact.string(todo)}</li>,
};
