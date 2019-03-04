let component = ReasonReact.statelessComponent("Header");

let make = (~title, _children) => {
  ...component,
  render: _self => (
    <h2 className="text-center">{ReasonReact.string(title)}</h2>
  )
}