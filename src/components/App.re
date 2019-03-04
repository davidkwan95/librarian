module Styles = {
  open Css;

  let container = style([
    marginTop(px(40))
  ])
}

let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  ...component,
  render: _self => (
    <div className={"container " ++ Styles.container}>
      <Header title="Book Finder" />
      <SearchContainer />
    </div>
  )
}
