let component = ReasonReact.statelessComponent("Header");

let make = (~title, _children) => {
  ...component,
  render: _self => (
    <div style=(ReactDOMRe.Style.make(~textAlign="center", ()))>
      {ReasonReact.string(title)}
    </div>
  )
}