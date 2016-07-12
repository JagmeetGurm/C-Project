using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(UsedGadgetsSale.Startup))]
namespace UsedGadgetsSale
{
    public partial class Startup {
        public void Configuration(IAppBuilder app) {
            ConfigureAuth(app);
        }
    }
}
